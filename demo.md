**1\. 查询指定项目属性**
###### 接口功能
> 获取制定项目的分类信息

###### URL
> http://api.tohack.com/upload

###### 支持格式
> JSON

###### HTTP请求方式
> GET

###### 请求参数
> |参数|必选|类型|说明|
|:-----  |:-------|:-----|-----                               |
|name    |ture    |string|请求的项目名                          |
|type    |true    |int   |请求项目的类型。1：类型一；2：类型二 。|

###### 返回字段
> |返回字段|字段类型|说明                              |
|:-----   |:------|:-----------------------------   |
|status   |int    |返回结果状态。0：正常；1：错误。   |
|company  |string | 所属公司名                      |
|category |string |所属类型                         |

###### 接口示例

|参数|必选|类型|说明|
|:----- |:------- |:----- |:----- |
|name |ture |string|请求的项目名 |
|type |true |int |请求项目的类型。1：类型一；2：类型二 。|

|返回字段|字段类型|说明 |
|:----- |:------ |:----------------------------- |
|status | int |返回结果状态。0：正常；1：错误。 |
|company | string | 所属公司名 |
|category | string |所属类型 |

~~~c
// 系统常量定义
defined('THINK_PATH')   or define('THINK_PATH',     __DIR__.'/');
defined('APP_PATH')     or define('APP_PATH',       dirname($_SERVER['SCRIPT_FILENAME']).'/');
defined('APP_STATUS')   or define('APP_STATUS',     ''); // 应用状态 加载对应的配置文件
defined('APP_DEBUG')    or define('APP_DEBUG',      false); // 是否调试模式
~~~

```sequence
Title: Here is a title
A->B: Normal line
B-->C: Dashed line
C->>D: Open arrow
D-->>A: Dashed open arrow
```

