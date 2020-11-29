## 板式文档转换接口-更新时间(20201129)
<form name="p2o" enctype="multipart/form-data" action="upload" method="post" target="_blank">
  <input type="file" name="file1"><br>
  <input type="submit" name="submit" value="PDF转换OFD" οnclick="javascript:document.p2o.submit();">
</form>

***
#### API调用接口地址
~~~html
<form name="p2o" enctype="multipart/form-data" action="http://api.tohack.com/upload" method="post" target="_blank">
    <input type="file" name="file1">
    <input type="submit" name="submit" value="PDF转换OFD" οnclick="javascript:document.p2o.submit();">
</form>
~~~
~~~json
// 返回值
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://api.tohack.com/ofd-process/0050090931.ofd"
}
~~~
***
#### 20201129
>   1.针对字体stroke线宽优化调整.
    2.字体坐标压缩优化(非规范)
#### 20201128
>   1.stroke线宽优化调整.
#### 20201126
>   1.stroke代码调整,统一入口.
    2.调整优化图片格式转换,增对mask(jb2格式)
#### 20201125
>   1.优化:增加图片格式转换jb2接口,增对部分灰度图像
    2.修改部分错误字符的gid导致排版错乱
#### 20201119
>   1.优化:增加图片格式转换jpeg接口,主要是动态生成的mask,增对灰度图像,可以更小
#### 20201118
>   1.绘图模式处理,根据不同的模式生成mask图片
#### 20201107
>   1.pdf图层优化,增对透明的放到背景层
    2.path增对ctm缩放线宽的调整
#### 20201106
>   1.pdf图层分租分块的处理
#### 20201105
>   1.clip优化
    2.文字的clip
#### 20201101
>   1.颜色渐变转图片
    2.path的clip增对图片的
    3.优化boundry,图片参数优化
#### 20201031
>   1.text优化(多行排版),坐标等浮点类型保留4位小数
#### 20201028
>   1.text处理优化,删除一些没用的字
    2.image旋转处理优化
#### 20201026
>   1.text和path的stroke参数调整(linewidth和miterlimit)
    2.image的mask处理,通过颜色生成图片(修改bug)
    3.添加渐变生成图片
#### 20201025
>   1.text的y坐标优化处理
    2.image的mask(颜色生成图片处理)
#### 20201020
>   1.文字boundary没有计算正确(已解决,text和path)
    2.文字没有hscale(已解决,text的变化,缩放等)
    3.渐变,裁剪没有
## OFD阅读器
***
## OFD数字签名,印章,签章,时间戳
***