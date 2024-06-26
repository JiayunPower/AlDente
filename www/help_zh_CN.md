## ChargeLimiter

&emsp;&emsp;ChargeLimiter(CL)是针对iOS开发的AlDente替代工具,适用于长时间过充情况下保护电池健康度.  
&emsp;&emsp;支持有根越狱(???-arm.deb)/无根越狱(???-arm64.deb )/TrollStore(???.tipa),目前支持iOS12-16.6.(注意: TrollStore环境下安装新版之前请先卸载旧版)   
&emsp;&emsp;测试过的环境: iPhone6/7+iOS12/13 Checkra1n/Unc0ver/Odyssey; iPhone7/X/11+iOS15/16 Palera1n/Dopamine/TrollStore.  
&emsp;&emsp;CL是开放式项目,如果有兴趣参与或者对CL有建议的的欢迎参提交代码.CL纯属偶然兴趣而开发,最开始是作者自己玩的,后来觉得其他人会需要才开源分享.CL承诺永久免费且无广告,但因为使用CL导致系统或硬件方面的影响(或认为会有影响的)作者不负任何责任,用户使用CL即为默认同意本条款.     

## 常见问题

什么情况下需要用CL?
* 手机需要长期连电源
* 手机需要整夜充电
* 充电时希望控制温度

CL更费电吗?
* 大多数用户感觉并不明显,CL的服务并不耗电,如果感觉确实耗电可以尝试关闭界面App和悬浮窗,或将更新频率调低到1分钟.

CL支持第三方电池吗?
* CL支持正版电池也支持大部分第三方品牌电池

使用CL后能增加健康度吗？
* 个人认为健康度递减是自然过程,软件更不可能直接修复硬件.不过有些用户使用CL一个月后确实健康度涨了.
* 大部分使用者会明显延缓电池健康度下降速度.
* 个别用户在使用CL后出现健康度下降更快的情况,请立即停用并卸载.
* 停充状态下一直连电源的情况下(非禁流),正常情况下电池电流为0,健康度永久不掉.

为什么手机用一会不充电了?(小白经常遇到的问题)
* CL并非傻瓜式工具,如果开启了温控请根据实际情况调整温度上下限,否则到达上限会停止充电,下限又无法达到自然无法充电.
* CL的设计思路就是减少充电次数,因此不会连着usb就充电,充电/停充都有触发条件,请仔细查看本页说明.
* 电池由于老化严重健康度低,刚启动系统时可以使用CL,一段时间后CL再也无法控制充电/停充.此种情况无法使用CL.

CL可以不依赖越狱或巨魔类工具吗?
* CL需要用到私有API所以无法上架.
* CL需要用到特殊签名因此无法以常规IPA方式来安装.

夏天怎样降低电池温度?
* 使用CL的Powercuff功能减少硬件用电量,充电状态下会同时降低充电功率
* 充电状态下,使用低功率充电头充电
* 购买手机散热器

## 测试电池兼容性

&emsp;&emsp;在使用CL前需要测试电池兼容性,如果不支持请放弃使用
* 1.测试电池是否支持停充.关闭CL全局开关,关闭"高级"中所有选项,在“正在充电”按钮开启的状态下,手动关闭之,若120秒内按钮有反应则电池支持停充,但如果停充后有较大持续电池电流(>=5mA)则无法支持停充(有些电池返回电池电流值有误,此时以实际电量变化为准).
* 2.测试电池是否支持智能停充.开启"高级-智能停充",其余同1.
* 3.测试电池是否支持禁流.关闭CL全局开关,在“电源已连接”按钮开启的状态下,手动关闭之,若120秒内按钮有反应则电池支持禁流,但如果禁流后有较大持续电流(>=5mA)则无法支持禁流(有些电池返回电池电流值有误,此时以实际电量变化为准).
* 有的电池因为老化而健康度过低,会出现刚重启系统时可以使用上述方式停充但过一段时间就再也无法停充,这种电池也无法被CL所兼容.
* 若电池既不支持停充也不支持禁流则永远不被CL支持.
* 如果使用CL过程中,健康度以不正常的方式下降,请自行调整高级菜单中的选项或卸载CL.

品牌反馈(欢迎汇报数据给我):
* 反馈不支持停充的电池: 马拉松1例.
* 反馈不支持SmartBattery的电池(开启SmartBattery会掉健康度): 品胜1例.

## 使用前必看

* iPhone8+存在120秒设定充电状态延迟. iPad可能也存在.
* 停充模式不会更新系统状态栏的充电标志,实际充电状态可以在看爱思助手或者CL查看.禁流模式会改变系统状态栏的充电标志(iPhone8+), 禁流模式在"高级-停充时启用禁流"中设定
* 对于TrollStore环境,因任何原因导致的服务被杀(比如重启系统/重启用户空间/...),将导致CL失效.
* CL的设计思路就是减少充电次数,因此不会连着usb就自发充电,也不会无故自动恢复充电,充电/停充都有触发条件,请仔细查看本页说明.
* 系统自带电池优化会导致CL失效,CL会自动关闭自带优化(但系统设置里不会显示).如果不使用CL需在系统设置中手动重置电池优化开关(先关后开).不推荐在过新的设备上使用,因为iPhone15起自带电池优化已经很完善.

## 使用说明

### 启用

&emsp;&emsp;设置全局启用,关闭后CL将恢复充电状态,并处于观察者模式,只读取电池信息,不进行任何操作.

### 悬浮窗

* 用于实时查看状态,同时查看服务是否正常运行
* 可拖动到任意位置
* 点击可切换CL全局启用状态
* 若设置为自动隐藏,前台有其他App时自动隐藏

### 模式

&emsp;&emsp;插电即充模式适合随用随充的普通用户使用:
* 重新接入电源且满足充电条件时开始充电
* 电量低于设定值时开始充电(为禁流设计)
* 电量高于设定值时停止充电
* 温度低于设定值时开始充电
* 温度高于设定值时停止充电

&emsp;&emsp;边缘触发模式适合手机常年连电源的工作室使用:
* 电量低于设定值时开始充电
* 电量高于设定值时停止充电
* 温度高于设定值时停止充电

&emsp;&emsp;触发优先级从高到低: 
* 充电(电量极低)
* 停充(电量>温度)
* 充电(电量>温度>插电)

### 更新频率

* 更新频率用于设定CL界面App和悬浮窗的数据更新频率.
* CL的服务并不耗电,界面App和悬浮窗会消耗少量的电,绝大多数用户并无感知.如果实测耗电,可以调低频率.

### 阈值设定

* 有研究表明电量在20%-80%之间,温度在10°C-35°C之间,对电池寿命影响最小.因此CL阈值默认设定为20/80/10/35,长期过充/电量耗尽/高温对电池会产生不良影响.    
* 温度阈值的设定,可根据"历史统计-小时数据"的温度数据设置合适的阈值.   
* 设定阈值和实际触发值不一定完全相同,例如设定80%上限结果到81%停充,大部分手机差距在0-1%,极少数3-5%,差异值与120秒延迟有关,与充电速度有关,也与电池质量有关.停充后如果存在微弱电流可能造成差值;另外健康度的突然变化也会影响电量.

### 行为

&emsp;&emsp;用于控制触发充电和停充时的行为,目前仅支持系统通知,每次重装CL需要重选以生效.

### 高级

* SmartBattery和智能停充,绝大多数用户使用默认配置即可,非正版电池如果使用默认配置导致健康度异常下降,可以自定义以最大程度减缓健康度下降速度.
* 自动禁流,用于兼容不支持停充的电池.开启禁流后等同于消耗电池电量,此时电池损耗和正常使用一致.
* 高温模拟,Powercuff,温度越高,硬件(充电器/CPU/GPU/背光/WiFi/无线/扬声器等)耗电越少,手机越卡顿,充电电流电压也越低.注意系统本身会根据实际情况调节该项,如果要强制指定模式(不建议)请打开锁定开关.越狱环境下如果存在功能冲突的tweak则CL不生效.
* 峰值性能,用于控制低温和电量不足时的峰值性能,不建议修改.
* 自动限流,用于自身流控不好的电池,电流过大会导致电池温度过高,健康度下降.选择合适的高温模拟等级: 可在电量小于30%时充电,电量越低时充电电流越高,手动设置"高级-高温模拟-设置"(等级从"正常"到"重度",等级越高电流越小),每次设置后几秒内可以观察到电流变化,达到合适的电流值时,将该等级设置到"高级-自动限流-高温模拟"中.自动限流在充电时自动设置为指定高温模拟等级(高级-自动限流-高温模拟),停充时自动恢复到默认等级(高级-高温模拟-设置).注意: 有些品牌电池可能无法控流,以实测为准.

### 电池信息

* 健康度与爱思助手保持一致,若健康度超过100%则说明新电池相比该代手机发行时的原始电池容量有升级.CL健康度是根据最大实际容量计算的.
* 硬件电量若超过100%(或超过显示电量)可能是未校准或质量问题导致.
* 电流以"瞬时电流"为准,电池电流为正说明从充电器流入电池,电池电流为负说明电池为设备供电.使用CL且停充状态下电池电流一般为0,此时电流流经电池为设备供电,电池起到闭合电路作用(可以理解为导线),此时对电池的损耗应小于仅使用电池为设备供电.禁流状态下电池电流一般为负.

### 历史统计

&emsp;&emsp;统计图用于查看一段时间内的电池状态,左右滑动可时移,点击上方标签可显示或隐藏特定指标

* 五分钟数据图,详细展示每次充放电时的电量/温度/电流及充电状态
* 小时数据图,概览充放电时的电量/温度/电流变化及充电状态
* 天数据图,详细展示每天健康度变化
* 月数据图,概览每月健康度变化

### 快捷指令
(适用于某些巨魔用户存在服务被杀导致软件失效的情况):  
+新建快捷指令 - 添加操作 - 类别 - "网页" - "Safari浏览器" - "打开URL"(以下是URL内容,标题自己设置)
* cl:///                        打开CL
* cl:///exit                    打开CL,退出CL(仅拉起服务)
* cl:///charge/exit      打开CL,启用充电,退出CL
* cl:///nocharge/exit    打开CL,停用充电,退出CL  

注意: 
* iPhone8+存在至多120秒延迟
* 可以在个人自动化中的电量事件使用上述指令实现指定电量开始/停止充电,也可以和其他模式结合实现开机自启(比如打开某App时触发)

集成快捷指令(iOS16+): <https://www.icloud.com/shortcuts/2ec3aed94f414378918f3e082b7bf6b0>

### HTTP接口(可配合快捷指令)

* 例子:

```bash
curl http://localhost:1230 -d '{"api":"get_conf","key":"enable"}' -H "content-type:application/json"
=> {"status":0,"data":true}
```

* 全局参数

|键                                            |类型         |描述                                                                                        |
|----------------------------------|-----------|---------------------------------------------------------------------|
|enable                                     |布尔         |关闭后CL将处于观察者模式,只读取电池信息,不进行任何操作|
|floatwnd                                  |布尔         |开启悬浮窗                                                                              |
|floatwnd_auto                         |布尔         |悬浮窗自动隐藏                                                                       |
|mode                                       |字符串     |模式,charge_on_plug为插电即充,edge_trigger为边缘触发     |
|charge_below                         |整型         |电量最小值                                                                              |
|charge_above                         |整型         |电量最大值                                                                              |
|enable_temp                           |布尔         |温控开关                                                                                 |
|charge_temp_above               |整型         |温度最小值                                                                              |
|charge_temp_below               |整型         |温度最大值                                                                              |
|acc_charge                             |布尔         |加速充电开关                                                                          |
|acc_charge_airmode              |布尔         |飞行模式                                                                                 |
|acc_charge_wifi                      |布尔         |WiFi                                                                                        |
|acc_charge_blue                    |布尔         |蓝牙                                                                                        |
|acc_charge_bright                  |布尔         |亮度                                                                                       |
|acc_charge_lpm                     |布尔         |低电量模式                                                                             |
|action                                     |字符串      |触发行为,noti为系统通知                                                       |
|adv_prefer_smart                   |布尔         |开启SmartBattery                                                                  |
|adv_predictive_inhibit_charge|布尔         |开启智能停充                                                                        |
|adv_disable_inflow                 |布尔         |开启禁流                                                                               |
|adv_limit_inflow                     |布尔         |开启限流                                                                                |
|adv_limit_inflow_mode          |字符串      |限流模拟高温等级,off/nominal/light/moderate/heavy           |
|adv_def_thermal_mode         |字符串      |默认模拟高温等级,off/nominal/light/moderate/heavy           |
|adv_thermal_mode_lock        |布尔         |模拟高温等级锁定                                                                  |
|thermal_simulate_mode         |字符串     |实际温度模拟等级(只读)                                                         |
|ppm_simulate_mode             |字符串      |(实际)峰值性能等级                                                               |
|use_smart                              |布尔         |是否支持SmartBattery(只读)                                                 |

* 获取配置get_conf

|请求         |类型         |描述                                     |
|------------|-----------|--------------------------------|
|api            |字符串    |get_conf                               |
|key            |字符串    |全局参数,若不指定则返回所有配置|
|响应         |                |                                            |
|status       |整型        |0:成功                                  |
|data         |                |数据                                     |

* 更改配置set_conf

|请求         |类型         |描述                                     |
|------------|-----------|--------------------------------|
|api            |字符串    |set_conf                               |
|key            |字符串    |全局参数                              |
|val            |               |值                                         |
|响应         |                |                                            |
|status       |整型        |0:成功                                  |
|data         |                |数据                                     |

* 获取电池数据get_bat_info

|请求         |类型         |描述                                     |
|------------|-----------|--------------------------------|
|api            |字符串    |get_bat_info                         |
|响应         |                |                                            |
|status       |整型        |0:成功                                  |
|data         |                |数据                                     |

|键                                        |类型        |描述                                     |
|-------------------------------|-----------|--------------------------------|
|Amperage                           |整型        |电流(mA)                              |
|AppleRawCurrentCapacity |整型        |原始电量(mAh)                     |
|BatteryInstalled                   |布尔        |电池已安装(mV)                   |
|BootVoltage                        |整型        |启动电压(mV)                       |
|CurrentCapacity                 |整型        |电量(%)                                |
|CycleCount                        |整型        |循环数                                  |
|DesignCapacity                  |整型        |设计容量(mAh)                     |
|ExternalChargeCapable     |布尔        |电源可充电                           |
|ExternalConnected            |布尔        |电源已连接                           |
|InstantAmperage                |整型        |瞬时电流(mA)                       |
|IsCharging                          |布尔        |正在充电                              |
|NominalChargeCapacity    |整型        |实际容量(mAh)                     |
|Serial                                  |字符串     |序列号                                 |
|Temperature                       |整型        |温度(℃/100)                        |
|UpdateTime                       |整型        |更新时间                              |
|AdapterDetails.Voltage      |整型        |电压(mV)                              |
|AdapterDetails.Current      |整型        |电源电流(mA)                      |
|AdapterDetails.Description|整型        |电源描述                             |
|AdapterDetails.IsWireless  |整型        |是否无线(需结合电源描述)  |
|AdapterDetails.Manufacturer|整型     |电源厂商                             |
|AdapterDetails.Name         |整型        |电源名称                             |
|AdapterDetails.Voltage      |整型        |电源电压(mV)                      |
|AdapterDetails.Watts         |整型        |电源功率(W)                        |

* 设置停充set_charge_status

|请求         |类型         |描述                                    |
|------------|-----------|-------------------------------|
|api            |字符串    |set_charge_status               |
|flag          |布尔         |启用                                     |
|响应         |                |                                            |
|status       |整型        |0:成功                                  |

* 设置禁流set_inflow_status

|请求         |类型         |描述                                    |
|------------|-----------|-------------------------------|
|api            |字符串    |set_inflow_status                |
|flag          |布尔         |启用                                     |
|响应         |                |                                            |
|status       |整型        |0:成功                                  |

