#### 上传PDF转OFD,PNG,SVG-服务更新时间(20201226)
<form name="pdf" action="http://api.tohack.com/pdf-convert?otype=ofd" enctype='multipart/form-data' method='POST'  target="iframeout">
     <input type="file" accept=".pdf" name="file" style="display:none" onchange="document.all.iframeout.style.display='';upload.click()" >
     <input type="button" onclick="file.click()" style="width:100%" value="单击选择PDF文档开始转换"/>
     <button type="submit" name="upload" style="display:none">上传</button>
</form>
<iframe width="100%" height="120" id="iframeout" name="iframeout" style="display:none"></iframe>
~~~json
// 返回值
{
    "status": 0,  // 0成功
    "speed": 120, // 处理时间,单位毫秒
    "data": "http://api.tohack.com/pdf-process/0050090931.ofd"
}
~~~
~~~html
<form name="pdf" enctype="multipart/form-data" action="http://api.tohack.com/pdf-convert?otype=ofd method="post" target="_blank">
    <input type="file" name="file1">
    <input type="submit" name="submit" value="PDF转换OFD" οnclick="javascript:document.pdf.submit();">
</form>
~~~
##### PDF转换接口功能描述
~~~
上传PDF文档转换为OFD,PNG,SVG,为了效率,上传方式为form提交
~~~
##### PDF转换测试接口地址
~~~
http://api.tohack.com/pdf-convert?otype=ofd|svg|png
~~~

***
#### 20201226
~~~
1.增加字体编码gbk转utf8
~~~
#### 20201218
~~~
1.PDF文档转图片上线,支持PNG,SVG格式
~~~
#### 20201216
~~~
1.图片处理优化
2.渐变色处理代码优化
~~~
#### 20201206
~~~
1.颜色渐变处理优化
~~~
#### 20201205
~~~
1.路径,文件剪切优化修改
2.路径颜色渐变优化修改
3.添加支持文字颜色渐变处理
~~~
#### 20201203
~~~
1.mask分组优化处理,增加异常处理
~~~
#### 20201202
~~~
1.字体优化,针对不是utf8的字体
~~~
#### 20201130
~~~
1.代码优化:针对stroke类型数据处理调整.
2.代码优化:字体坐标压缩优化
~~~
#### 20201129
~~~
1.针对字体stroke线宽优化调整.
2.字体坐标压缩优化(非规范)
3.针对颜色优化调整
~~~
#### 20201128
~~~
1.stroke线宽优化调整.
~~~
#### 20201126
~~~
1.stroke代码调整,统一入口.
2.调整优化图片格式转换,增对mask(jb2格式)
~~~
#### 20201125
~~~
1.优化:增加图片格式转换jb2接口,增对部分灰度图像
2.修改部分错误字符的gid导致排版错乱
~~~
#### 20201119
~~~
1.优化:增加图片格式转换jpeg接口,主要是动态生成的mask,增对灰度图像,可以更小
~~~
#### 20201118
~~~
1.绘图模式处理,根据不同的模式生成mask图片
~~~
#### 20201107
~~~
1.pdf图层优化,增对透明的放到背景层
2.path增对ctm缩放线宽的调整
~~~
#### 20201106
~~~
1.pdf图层分租分块的处理
~~~
#### 20201105
~~~
1.clip优化
2.文字的clip
~~~
#### 20201101
~~~
1.颜色渐变转图片
2.path的clip增对图片的
3.优化boundry,图片参数优化
~~~
#### 20201031
~~~
1.text优化(多行排版),坐标等浮点类型保留4位小数
~~~
#### 20201028
~~~
1.text处理优化,删除一些没用的字
2.image旋转处理优化
~~~
#### 20201026
~~~
1.text和path的stroke参数调整(linewidth和miterlimit)
2.image的mask处理,通过颜色生成图片(修改bug)
3.添加渐变生成图片
~~~
#### 20201025
~~~
1.text的y坐标优化处理
2.image的mask(颜色生成图片处理)
~~~
#### 20201020
~~~
1.文字boundary没有计算正确(已解决,text和path)
2.文字没有hscale(已解决,text的变化,缩放等)
3.渐变,裁剪没有
~~~
#### 20201013
~~~
1.PDF转OFD板式文档服务上线
~~~