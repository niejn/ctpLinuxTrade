// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include "ThostFtdcTraderApi.h"
#include "TraderSpi.h"
#include <iostream>
using namespace std;
// UserApi对象
CThostFtdcTraderApi* trader_pUserApi;

// 配置参数
char  TRADER_FRONT_ADDR[] = "tcp://180.168.146.187:10000";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "051444";			// 投资者代码
TThostFtdcPasswordType  PASSWORD = "123456";			// 用户密码
TThostFtdcInstrumentIDType TRADER_INSTRUMENT_ID = "m1709";	// 合约代码
//int iInstrumentID = 1;
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 35960; // 38850;				// 价格

// 请求编号
int trader_iRequestID = 0;

int main(void)
{
    cout << "Hello world" << endl;
    // 初始化UserApi
    trader_pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
    CTraderSpi* trader_pUserSpi = new CTraderSpi();
    trader_pUserApi->RegisterSpi((CThostFtdcTraderSpi*)trader_pUserSpi);			// 注册事件类
    trader_pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);				// 注册公有流
    trader_pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// 注册私有流
    trader_pUserApi->RegisterFront(TRADER_FRONT_ADDR);							// connect
    trader_pUserApi->Init();

    trader_pUserApi->Join();
    return 0;
//	trader_pUserApi->Release();
}