//
//  SobotLoginTools.h
//  SobotUI
//
//  Created by zhangxy on 2022/11/22.
//

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>
#import "SobotLoginEntity.h"
#define SobotNotification_PermissionsRefresh @"SobotNotification_PermissionsRefresh"
#define KVAppLoginDict @"SobotAppLoginInfo"
NS_ASSUME_NONNULL_BEGIN

// 主要是登录APP或在线SDK时使用
@interface SobotLoginParams:SobotBaseEntity

@property(nonatomic,strong) NSString *loginEmail;
@property(nonatomic,strong) NSString *loginPwd;

@property(nonatomic,assign) int loginStatus;
@property(nonatomic,assign) int appRegion;
@property(nonatomic,strong) NSString *appVersion;

@end

/// 登录
@interface SobotLoginTools : NSObject

/**
 *  单例
 *
 *  @return ZZLibNetworkTools创建的对象
 */
+(SobotLoginTools *) shareSobotLoginTools;

-(void)config:(NSString *) apiHost accessTokenHost:(NSString *) achost version:(NSString *)sdkVersion;

-(SobotLoginEntity *) getLoginInfo;


-(BOOL) isLogin;
-(BOOL) checkSupportV6;
-(NSString *)getTempId;
-(NSString *)getToken;
-(NSString *)getLoginAccessToken;
-(NSString *)getServiceEmail;


// 获取当前登录使用的语言，如果为空默认给zh
-(NSString *)getCurLanguage;

// 获取当前时区的前面时间间隔  例如北京 +8 夏威夷-10
-(NSInteger)getCurTimeZoneNumber;
// 获取当前登录用户的时区，如果为空，默认当前系统[NSTimeZone systemTimeZone]
-(NSTimeZone *)getCurTimeZone;

/// 检查当前token是否有效
-(BOOL )checkExpiresToken;

// 移除本地token，如果需要强制登录，执行此操作
-(void) removeExpiresToken;




/// 执行APP登录接口
/// - Parameters:
///   - loginAcount: 用户名
///   - loginPwd: 密码
///   - version: app版本
///   - loginStatue: 当前登录状态
///   - resultBlock: 结果
///   --包含登录客服的所有属性，不包含accessToken
///   -- 用户信息，新旧权限信息
-(void)doAppLogin:(NSString *  _Nullable)loginAcount pwd:(NSString *  _Nullable)loginPwd appVersin:(NSString *)version status:(int) loginStatue appRegion:(int)appRegion result:(void (^)(NSInteger code, NSDictionary * _Nullable, NSString * _Nullable))resultBlock;

/// 登录
/// - Parameters:
///   - loginAcount: 账号
///   - loginPwd: 如果当前已经登录，不要传此参数
///   - appParams: 如果是APP登录，需要配置APP相关参数
///   - resultBlock: 登录结果，包含token和用户信息，不包含accessToken
-(void)doLogin:(NSString *  _Nullable)loginAcount pwd:(NSString *  _Nullable)loginPwd appParams:(SobotLoginParams *  _Nullable)inParams result:(void (^)(NSInteger code, NSDictionary * _Nullable, NSString * _Nullable))resultBlock;



/// 使用公司appkey登录
/// - Parameters:
///   - app_key: key
///   - appid: id
///   - email: 坐席账号
///   - appParams: 如果是APP登录，需要配置APP相关参数
///   - resultBlock: 登录结果
-(void)loginWithAppkey:(NSString *)app_key appid:(NSString *) appid email:(NSString *) email appParams:(SobotLoginParams * _Nullable) appParams result:(void (^)(NSInteger code, NSDictionary * _Nullable, NSString * _Nullable))resultBlock;


/// 使用公司token登录
/// - Parameters:
///   - companyToken: 公司token
///   - email: 当前坐席的账号
///   - appParams: 如果是APP登录，需要配置APP相关参数
///   - resultBlock: 登录结果
-(void)loginWithCompanyToken:(NSString *)companyToken email:(NSString *) email  appParams:(SobotLoginParams * _Nullable) appParams result:(void (^)(NSInteger code, NSDictionary * _Nullable, NSString * _Nullable))resultBlock;

/// 获取登录信息
/// - Parameter resultBlock: 如果判断当前支持V6，会自动获取accessToken
-(void)getLoginUserInfo:(void (^)(NSInteger code,NSDictionary * _Nullable dict,NSString * _Nullable msg))resultBlock;


/// 获取当前的accesToken
/// - Parameters:
///   - token: 需要先登录成功
///   - resultBlock: 获取结果
-(void)getAccessTokenWithApi:(NSString *) token result:(void(^)(NSInteger code,NSDictionary * _Nullable dict,NSString * _Nullable msg)) resultBlock;


/// 退出登录
/// - Parameters:
///   - resultBlock: 结果
-(void)logOut:(void(^)(NSInteger code,NSDictionary * _Nullable dict,NSString * _Nullable msg)) resultBlock;


/// 清理登录数据，退出登录成功接口，会主动调用
/// 当被踢下线时，可单独调用此接口

//-(void)clearLoginInfo;
-(void)clearLoginToken;

-(void)clearLoginInfo;

-(void)clearLoginInfo:(BOOL)isClearHost;

/// 查询当前登录用户的主域名
-(NSString *) getApiHost;

/// 查询当前登录用户开放接口域名
-(NSString *) getOpenApiHost;


/// 查询当前登录用户的所有服务域名属性
-(NSDictionary *) getHostObject;


///  查询当前账号支持的域名
/// - Parameters:
///   - account: 当前账号
///   - pwd: 账号密码
///   - apiMainhost: 查询所需要的环境
///   - resultBlock:
///   code = 1说明成功，当items不为空时，说明当前是多个域名，需要调用saveHost:函数选择一个
-(void)getApiHostAddress:(NSString *)account password:(NSString *) pwd with:(NSString *) apiMainhost result:(void(^)(NSInteger code,NSMutableArray * _Nullable items,NSString * _Nullable host)) resultBlock;


/// 多个域名环境时，选中后设置域名
/// - Parameter checkItem: 当前选择的环境
-(void)saveHost:(NSDictionary *) checkItem;


@end

NS_ASSUME_NONNULL_END
