import cv2
import numpy as np


def get_center(image):
    # image是已经裁剪过的图像
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  # 获得灰度图
    b = image[:, :, 0]  # 获得b通道图
    g = image[:, :, 1]  # 获得g通道图
    r = image[:, :, 2]  # 获得r通道图

    # L_x,L_y是剪切后图像的宽高
    L_x = image.shape[0]

    index = 0
    index_2 = 0  # 2色块数
    index_3 = 0  # 3色块数

    center_1 = []

    for i in range(0, 4):
        # 分别对BGR通道和灰度图处理
        if i == 0:
            img = b
        elif i == 1:
            img = g
        elif i == 2:
            img = r
        else:
            img = gray

        # 获得高斯模糊后图像
        blurred = cv2.GaussianBlur(img, (3, 3), 0)

        # canny算法边缘检测
        canny = cv2.Canny(blurred, 12, 40)

        # 边缘线膨胀
        kernel = np.ones((3, 3), np.uint8)  # 3x3掩膜
        dilated = cv2.dilate(canny, kernel, iterations=2)

        (contours, hierarchy) = cv2.findContours(dilated.copy(),
                                                 cv2.RETR_TREE,
                                                 cv2.CHAIN_APPROX_SIMPLE)

        hierarchy = hierarchy[0]

        for component in zip(contours, hierarchy):
            contour = component[0]
            peri = cv2.arcLength(contour, True)
            approx = cv2.approxPolyDP(contour, 0.1 * peri, True)
            area = cv2.contourArea(contour)
            corners = len(approx)

            # compute the center of the contour
            M = cv2.moments(contour)

            if M["m00"]:
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"])
            else:
                cX = None
                cY = None

            if 3 <= corners <= 4:
                if 10000 < area < 90000 and cX is not None:  # 单一色块轮廓 TODO 实际面积需要确定
                    tmp = [1, index, cX, cY, int(0.15 * cX + cY)]
                    if index == 0:
                        center_1 = [tmp]
                    else:
                        center_1 = np.row_stack((center_1, tmp))
                    index += 1

                elif 170000 < area < 280000 and cX is not None:  # 两相同色块轮廓
                    tmp = [2, index, cX, cY, int(0.15 * cX + cY)]
                    if index == 0:
                        center_1 = [tmp]
                    else:
                        center_1 = np.row_stack((center_1, tmp))
                    index += 1
                    index_2 += 1

                elif 300000 < area < 400000 and cX is not None:  # 三相同色块轮廓
                    tmp = [3, index, cX, cY, int(0.15 * cX + cY)]
                    if index == 0:
                        center_1 = [tmp]
                    else:
                        center_1 = np.row_stack((center_1, tmp))
                    index += 1
                    index_3 += 1

    center = np.array(center_1)
    # 排序
    c2 = np.lexsort(-center.T[:5, :])
    center = center[c2, :]
    c2 = np.lexsort(center.T[:1, :])
    center = center[c2, :]

    # 2色块相连处理
    for i in range(1, index_2 + 1):
        cx = center[index - i - index_3][2]
        cy_u = center[index - i - index_3][3] + 60
        cy_l = center[index - i - index_3][3] - 60
        tmp = [[1, index - i - index_3, cx, cy_u, int(0.15 * cx + cy_u)],
               [1, index - i - index_3, cx, cy_l, int(0.15 * cx + cy_l)]]
        center = np.delete(center, index - i - index_3, 0)
        center = np.row_stack((center, tmp))

    index = index + index_2
    c2 = np.lexsort(center.T[:1, :])
    center = center[c2, :]
    # 3色块相连处理
    for i in range(1, index_3 + 1):
        cx = center[index - i][2]
        cy_u = center[index - i][3] + 120
        cy_l = center[index - i][3] - 120
        tmp = [[1, index - i, cx, cy_u, int(0.15 * cx + cy_u)], [1, index - i, cx, cy_l, int(0.15 * cx + cy_l)]]
        center = np.row_stack((center, tmp))
    index = index + 2 * index_3

    c2 = np.lexsort(-center.T[:5, :])
    center = center[c2, :]

    Cxm = center[0][3] - center[index - 1][3]
    # 删除冗余项
    for i in range(0, index):
        j = i + 1
        while i < j < index:
            if 0.35 * L_x <= center[j, 3] <= 0.65 * L_x and 0.35 * L_x <= center[i, 3] <= 0.65 * L_x:
                ly = 0.15
                lx = 0.12
            else:
                ly = 0.12
                lx = 0.2
            if abs(center[j, 3] - center[i, 3]) <= int(ly * Cxm) and abs(center[j, 2] - center[i, 2]) <= int(lx * Cxm):
                center = np.delete(center, j, 0)
                index = index - 1
            else:
                center = center
                j += 1

    c2 = np.lexsort(center.T[:3, :])
    center = center[c2, :]
    center_list = []

    if len(center) == 14:
        row1 = center[0:6, 2:4]
        row1 = row1[np.lexsort(row1.T[:1, :]), :]
        row2 = center[6:8, 2:4]
        row2 = row2[np.lexsort(row2.T[:1, :]), :]
        row3 = center[8:14, 2:4]
        row3 = row3[np.lexsort(row3.T[:1, :]), :]

        row = np.concatenate((row1, row2, row3))
        center_list = row.tolist()
    else:
        print('error!')
    return center_list
