﻿#ifndef LIGHTCMDLIST_H
#define LIGHTCMDLIST_H

/*****************************************************************************************
 * 说明： 40命令，设置雾灯4个区域显示颜色
 *      1. 1红 2绿 3蓝 4白 5黄 6青 7洋红 8黑 9橙
 *      2. %1 %2 %3 %4 对应四个区的颜色，左上，右上，左下，右下
 *      3. %5 设置有效数值：
 *          00 只用 %1 数值设置四个区
 *          ff 使用所有数值对应设置所有区
 *
 * 例：
 *      FF 40 FF 01 02 03 04 FF AA //广播分区显示：左上红，右上绿，左下蓝，右下白
 *****************************************************************************************/
#define CHANGE_LIGHT_COLOR "FF 40 FF %1 02 03 04 %2 AA"

/*****************************************************************************************
 * 说明：55命令，设置雾灯的显示内容
 *      %1 雾灯 ID
 *      %2 文字16进制
 *
 * 预设：
 *    第一批: 红蓝颜色闪烁亮度均不可调，其他可正常调
 *       A0 F3 0 左右红蓝2次快闪16:40 2023/7/3
 *       A0 F5 1 左右红蓝3次快闪
 *       A0 F4 2 上下红蓝1次高亮
 *       A0 F2 3 上下红蓝1次低亮
 *       A0 F6 4 左下箭头
 *       A0 F7 5 右下箭头
 *       A0 F8 6 右上分流箭头长
 *       A0 F9 7 右上分流箭头短
 *
 *   第二批: 有颜色为带默认颜色，其他同文字均可调整
 *       A0 E0 红_车道关闭
 *       A0 E1 黄_反向弯路1
 *       A0 E2 黄_反向弯路2
 *
 *       A0 E4 黄_线型诱导标上双
 *       A0 E5 黄_线型诱导标右单
 *       A0 E6 黄_线型诱导标右双
 *       A0 E7 黄_线型诱导标左单
 *       A0 E8 黄_线型诱导标左双
 *       A0 E9 绿_车道开放
 *       A0 EA 蓝_向右换道
 *       A0 EB 蓝_向右驶离
 *       A0 EC 蓝_向左换道
 *       A0 ED 蓝_向左驶离
 *
 * 例：
 *      FF 55 FF A0 F2 AA // 所有灯上下单次低亮交替
 *******************************************************************************************/
#define DISPLAY_FONT "FF 55 %1 %2 AA"

/*******************************************************************************************
 * 说明：66命令，设置雾灯的亮度
 *      %1 雾灯 ID
 *      %2 亮度值的16进制
 *
 *******************************************************************************************/
#define CMD_LUMINANCE "FF 66 FF %1 00 AA"
#define MAX_LUMINANCE 100
#define MINI_LUMINANCE 0


/*******************************************************************************************
 * 说明：77命令，设置雾灯的闪烁
 *      %1 亮灯时长
 *      %2 灭灯时长
 *
 *******************************************************************************************/
#define CMD_FLICKER "FF 77 FF %1 %2 AA"


/*******************************************************************************************
 * 说明：20命令，雾灯电源开关
 *******************************************************************************************/
#define CMD_POWER_ON    "FF 20 FF 01 01 AA"    // 开
#define CMD_POWER_OFF   "FF 20 FF 00 00 AA"    // 关

/*******************************************************************************************
 * 说明：08命令，轨迹跟踪功能
 *      %1 编号，FF 为全部
 *
 *******************************************************************************************/
#define CMD_PATH_TRACKING_ON_1  "FF 08 %1 01 01 AA"     // 模式1 开
#define CMD_PATH_TRACKING_ON_2  "FF 08 %1 02 02 AA"     // 模式2 开
#define CMD_PATH_TRACKING_OFF   "FF 08 %1 00 00 AA"     // 关

/*******************************************************************************************
 * 说明：09命令，轨迹跟踪时间设置
 *      范围 1 - 20 秒
 *      %1 编号，FF 为全部
 *      %2 时间的16进制，单位0.1秒 [0A == 10 * 0.1 == 1秒]
 *
 *******************************************************************************************/
#define CMD_PATH_TRACKING_SET   "FF 09 %1 %2 00 AA"

/*******************************************************************************************
 * 说明：10命令，查询命令
 *      %1 编号 不支持群发
 *      CMD_STATUS_QUERY_1  查询控制板状态
 *          返回信息f5 x5两个字节, x=0灯关闭 x=1 灯亮   x=3灯亮且闪烁  x=4内部通讯故障
 *      CMD_STATUS_QUERY_2  查询控制板电源状态
 *          返回信息f6 x5两个字节, x=0电源接通（节能关闭）   x=1电源断开（节能开启）
 *      CMD_STATUS_QUERY_3  轨迹跟踪延时时间查询
 *          返回信息  fa  xx  时间，xx为16进制，单位0.1秒
 *      CMD_STATUS_QUERY_5  轨迹跟踪状态查询
 *          0A 关闭  1A跟踪模式1  2A 跟踪模式2
 *
 *******************************************************************************************/
#define CMD_STATUS_QUERY_1   "FF 10 %1 00 01 AA"    // 查询控制板状态
#define CMD_STATUS_QUERY_2   "FF 10 %1 00 02 AA"    // 查询控制板电源状态
#define CMD_STATUS_QUERY_3   "FF 10 %1 00 03 AA"    // 轨迹跟踪延时时间查询
#define CMD_STATUS_QUERY_5   "FF 10 %1 00 05 AA"    // 轨迹跟踪状态查询

#endif // LIGHTCMDLIST_H
