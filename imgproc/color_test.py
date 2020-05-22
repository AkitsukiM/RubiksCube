import collections


# 定义HSV颜色字典，参考网上HSV颜色分类
def get_color_list():
    dict0 = collections.defaultdict()
    # 定义字典存放颜色分量上下限
    # 例如：{颜色: [min分量, max分量]}

    # 白色
    lower_white = [0, 0, 46]
    upper_white = [180, 51, 255]
    color_list = [lower_white, upper_white]
    dict0["white"] = color_list
    # 红色
    lower_red = [0, 52, 46]
    upper_red = [5, 255, 255]
    color_list = [lower_red, upper_red]
    dict0["red"] = color_list
    # 红色2
    lower_orange = [175, 52, 46]
    upper_orange = [180, 255, 255]
    color_list = [lower_orange, upper_orange]
    dict0["orange2"] = color_list
    # 橙色
    lower_orange = [9, 52, 46]
    upper_orange = [25, 255, 255]
    color_list = [lower_orange, upper_orange]
    dict0["orange"] = color_list
    # 黄色
    lower_yellow = [25, 52, 46]
    upper_yellow = [45, 255, 255]
    color_list = [lower_yellow, upper_yellow]
    dict0["yellow"] = color_list
    # 绿色
    lower_green = [46, 52, 46]
    upper_green = [77, 255, 255]
    color_list = [lower_green, upper_green]
    dict0["green"] = color_list
    # 蓝色
    lower_blue = [78, 52, 46]
    upper_blue = [100, 255, 255]
    color_list = [lower_blue, upper_blue]
    dict0["blue"] = color_list
    return dict0


# 特性像素点的RGB值转成HSV值，返回的HSV是列表
def rgb2hsv(r, g, b):
    r, g, b = r / 255.0, g / 255.0, b / 255.0
    mx = max(r, g, b)
    mn = min(r, g, b)
    v = mx

    m = mx - mn
    if mx == 0:
        s = 0
    else:
        s = m / mx

    if mx == mn:
        h_local = 0
    elif mx == r:
        if g >= b:
            h_local = ((g - b) / m) * 60
        else:
            h_local = ((g - b) / m) * 60 + 360
    elif mx == g:
        h_local = ((b - r) / m) * 60 + 120
    elif mx == b:
        h_local = ((r - g) / m) * 60 + 240

    H = h_local / 2
    S = s * 255.0
    V = v * 255.0

    HSV = [H, S, V]
    return HSV


# 返回颜色列表&颜色标识符
def get_color(center, img):
    # center 是列表， img是cv2.imread读入的裁剪过的图像（原来的彩色图像）
    num = len(center)

    # 调用颜色表
    color_0 = []
    color_dict = get_color_list()  # {颜色: [min分量, max分量]}
    c2num = [[1, "white"], [2, "blue"], [3, "red"], [3, "red2"], [4, "orange"], [4, "orange2"],
             [5, "green"], [6, "yellow"]]
    index = 0
    # 将每一个色块对比
    for i in range(num):
        cx = center[i][0]
        cy = center[i][1]
        data = img[cy, cx]  # 读入的img是BGR型
        data2 = rgb2hsv(data[2], data[1], data[0])

        # 遍历颜色表与 data 进行对比
        for k_color in color_dict:
            color_low = color_dict[k_color][0]  # 下限
            color_high = color_dict[k_color][1]  # 上限
            k = 0
            for j in range(3):
                if (data2[j] >= color_low[j]) & (data2[j] <= color_high[j]):
                    k += 1
                else:
                    break

            if k == 3:
                for j in range(len(c2num)):
                    if k_color == c2num[j][1]:
                        dict1 = {"index": index, "cx": cx, "cy": cy, "color": k_color, "number": c2num[j][0]}
                        color_0.append(dict1)
                        break
                index += 1
            else:
                continue

    return color_0
