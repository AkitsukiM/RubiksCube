import get_point  # 先用原图识别出轮廓，然后判断出中心点
import color_test  # 判断中心点的颜色
import cv2

print("请输入图片文件所在的文件夹路径")
folder = input("please input the folder path of the pictures:")
print("-" * 20)
print("请输入图片文件的个数")
num_pic = input("please input the amount of the pictures:")
print("-" * 20)

for i in range(int(num_pic)):
    # 读入图像
    # filename = r'D:\mofang\pic_%d.jpg' % (i + 1)  # TODO 实际存储位置？
    filename = folder + '\\' + 'pic_%d.jpg' % (i + 1)
    image = cv2.imread(filename)
    # 剪切图片
    height = image.shape[0]
    width = image.shape[1]
    image = image[int(0 * height):int(1 * height), int(0.25 * width):int(0.7 * width)]
    # height, width = image.shape[:2]
    # size = (int(width * 0.3), int(height * 0.3))
    # image = cv2.resize(image, size, interpolation=cv2.INTER_AREA)
    # 获取中心点坐标,顺序先x再y
    center = get_point.get_center(image)
    # 识别中心点颜色
    color_c = color_test.get_color(center, image)  # {"index": index, "cx": cx, "cy": cy, "color": k_color, "number"}
    print("result of img %s " % filename)
    # 对应成数字
    # number_list = save_color.color2number(color)  # {"index": index, "cx": cx, "cy": cy, "color": k_color, "number"}
    # 整理
    len_num = len(color_c)
    result = []
    if len_num == 14:
        for a in range(len_num):
            result.append(color_c[a]["number"])
    else:
        print("error!")
        continue

    # 输出txt
    j = i + 1
    save_filename = 'ipt_%d.txt' % j
    file = open(save_filename, mode='w')
    for k in range(len_num):
        # 去除[],单引号，逗号，末尾不换行
        s = str(result[k]).replace("[", "").replace("]", "")
        s = s.replace("'", "").replace(",", "")  # + '\n'
        file.write(s)
    file.close()
    print("导出txt ipt_%d成功。" % j)
