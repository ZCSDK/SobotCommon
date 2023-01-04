//
//  SobotChatMessage.h
//  SobotCommon
//
//  Created by zhangxy on 2022/8/30.
//

#import "SobotBaseEntity.h"

/**消息体类型*/
typedef NS_ENUM(NSInteger,SobotMessageType) {
    SobotMessageTypeText  = 0, //文本
    SobotMessageTypePhoto = 1, //图片
    SobotMessageTypeSound = 2, // 声音
    SobotMessageTypeVideo = 3, // 视频
    SobotMessageTypeFile  = 4, // 文件
    SobotMessageTypeRichJson = 5, // 对象
    SobotMessageTypeRichJsonLoop = 9, // 对象
    SobotMessageTypeHotGuide = 7,// 热门引导问题
    SobotMessageTypeLocation  = 22, // 位置
    SobotMessageTypeCard = 24,//商品卡片消息
    SobotMessageTypeOrder= 25,//订单卡片消息
    SobotMessageTypeTipsText  = -1, //这是一条提示语
    SobotMessageTypeStartSound = -4,//正在录音
    SobotMessageTypeCancelSound = -5,//取消正在闪烁的语音cell
};

typedef NS_ENUM(NSInteger,SobotMessageRichJsonType) {
//    对象类型：
    SobotMessageRichJsonTypeText  = 0,//-富文本
    SobotMessageRichJsonTypeLoop = 1, //多轮
    SobotMessageRichJsonTypeLocation = 2, // 位置
    SobotMessageRichJsonTypeGoods = 3, // 商品卡片
    SobotMessageRichJsonTypeOrder  = 4, // 订单
    SobotMessageRichJsonTypeApplet  = 6, // 小程序卡片
    SobotMessageRichJsonTypeArticle = 17,// 文章
};

typedef NS_ENUM(NSInteger,SobotMessageFileType) {
    SobotMessageFileTypeDoc  = 13,//doc文件格式
    SobotMessageFileTypePpt  = 14,//ppt文件格式
    SobotMessageFileTypeXls  = 15,//xls文件格式
    SobotMessageFileTypePdf  = 16,//pdf文件格式
    SobotMessageFileTypeMp3  = 17,//mp3文件格式
    SobotMessageFileTypeMp4  = 18,//mp4文件格式
    SobotMessageFileTypeZip  = 19,//压缩文件格式
    SobotMessageFileTypeTxt  = 20,//txt文件格式  或 7
    SobotMessageFileTypeUnkonw  = 21,//其他文件格式
};


/**下推消息类型*/
typedef NS_ENUM(NSInteger,SobotMessageActionType) {
    SobotMessageActionTypeSendGoods    = -2,// 未知类型
    SobotMessageActionTypeUnKonw    = -1,// 未知类型
    SobotMessageActionTypeEvaluationCompleted                          = 0,
    /** 转人工成功 */
    SobotMessageActionTypeOnline                           = 1,
    /** 转人工排队 */
    SobotMessageActionTypeWaiting                          = 2,
    /** 暂无客服在线 */
    SobotMessageActionTypeUserNoAdmin                      = 3,
    /** 暂时无法评价 */
    SobotMessageActionTypeTemporarilyUnableToEvaluate      = 4,
    /** 已完成评价 */
    SobotMessageActionTypeDefault             = -2,
    /** 咨询后才可评价 */
    SobotMessageActionTypeAfterConsultingEvaluation        = 6,
    /** 已下为新消息 */
    SobotMessageActionTypeNewMessage                       = 7,
    /** 空消息 */
    SobotMessageActionTypeNullMessage                      = 8,
    /** 机器人欢迎语 */
    SobotMessageActionTypeRobotHelloWord                   = 9,
    /** 用户超时提示语 */
    SobotMessageActionTypeUserTipWord                      = 10,
    /** 客服超时提示语 */
    SobotMessageActionTypeAdminTipWord                     = 11,
    /** 拉黑，暂时无法转人工 */
    SobotMessageActionTypeIsBlock                          = 12,
    /** 用户超时下线 */
    SobotMessageActionTypeUserOutWord                      = 13,
    /** 发送和接收的消息内容 文件路径 */
    SobotMessageActionTypeText                             = 14,
    /** 人工欢迎语 */
    SobotMessageActionTypeAdminHelloWord                   = 15,
    /** 本次会话结束 */
    SobotMessageActionTypeOverWord                         = 16,
    /** 您打开了新窗口，本次会话结束 */
    SobotMessageActionTypeOpenNewWindow                    = 17,
    /** 评价 */
    SobotMessageActionTypeEvaluation                       = 18,
    
    /** 排队达到阀值*/
    SobotMessageActionTypeWatingFull                       = 19,
    /** 消息撤回*/
    SobotMessageActionTypeRevertMsg                        = 20,
    
    /** 安全提示 */
    SobotMessageActionTypeSafety                           = 21,
    
    /*** 您的留言状态有更新  ***/
    SobotMessageActionTypeUpdateLeave                      = 22,
    
    /***** 情绪转人工和重复提问转人工 提示文案   ****/
    SobotMessageActionTypeRobotTurnMsg                     = 23,
    
    /****** 留言转离线消息 ******/
    SobotMessageActionTypeOrderLeave                        = 24,
    
    /****** 您的留言已提交成功 *****/
    SobotMessageActionTypeLeaveSuccess                      = 25,
    /****** 通告消息 *****/
    SobotMessageActionTypeNotice                            = 26,
    /****** 诈骗词告警消息 *****/
    SobotMessageActionTypeChatWarning                       = 29,
    /**机器人点踩 触发转人工*/
    SobotMessageActionTypeUnresolvedProblemTurn             = 30,
    /****** 发送留言转离线消息后，结束会话 *****/
    SobotMessageActionTypeChatCloseByLeaveMsg               = 99,
    
    
    /**
         * 用户咨询页授权
         */
    SobotMessageActionTypeChat_AUTH_SAFETY = 43,

        /**
         * 用户同意敏感词授权
         */
    SobotMessageActionTypeChat_AUTH_AGREE = 44,

        /**
         * 用户拒绝敏感词授权
         */
    SobotMessageActionTypeChat_AUTH_REFUSE = 45,
    /**
     * 用户排队超时离线
     */
    SobotMessageActionTypeChat_WaitingOut = 46,
    /**
     * 用户排队超时离线提醒
     */
    SobotMessageActionTypeChat_WaitingOutTips = 47,
    /**
     * 用户排队超时离线提醒,继续排队
     */
    SobotMessageActionTypeChat_WaitingContinueTips = 48,
    SobotMessageActionTypeChat_WaitingContinueMsg = 49,
    SobotMessageActionTypeTransferTips = 50
};

NS_ASSUME_NONNULL_BEGIN

// richList and loopchat
@interface SobotChatRichContent : SobotBaseEntity

// richList 消息体
@property(nonatomic,copy) NSString *height;//": null,
@property(nonatomic,copy) NSString *width;//":
@property(nonatomic,copy) NSString *fileSize;//":
@property(nonatomic,copy) NSString *list;//": null,
@property(nonatomic,copy) NSString *msg;//,
@property(nonatomic,copy) NSString *name;//": null,
@property(nonatomic,copy) NSString *showType;//": null,

// 富文本数组:0：文本，1：图片，2：音频，3：视频，4：文件
@property(nonatomic,assign) SobotMessageType type;//": 0
// end

@property(nonatomic,copy) NSMutableAttributedString *attr;

// 多伦
@property(nonatomic,copy) NSString *leaveTemplateId;//": "测试多轮",
@property(nonatomic,assign) int templateId;//": 0,
@property(nonatomic,copy) NSString *question;//": "测试多轮",
@property(nonatomic,assign) int level;//": 0,
@property(nonatomic,copy) NSString *conversationId;//": "cc047a23-797c-4424-85b0-de7f689ebd8f",
@property(nonatomic,copy) NSString *docId;//": "e7a9c56c3a2a4621916fee3a563d2072",
@property(nonatomic,copy) NSString *groupId;//": "a2df4376421c490ba94b48c7d0e8e91c",
@property(nonatomic,copy) NSString *remindQuestion;//": "<p>姓名？</p>",
@property(nonatomic,assign) BOOL endFlag;//": false,
@property(nonatomic,copy) NSString *levelName;//": "节点1",
@property(nonatomic,copy) NSString *retCode;//": "000000",
@property(nonatomic,copy) NSString *inputContentList;//": "贾渣渣,默默,小王八",
@property(nonatomic,copy) NSString *outPutParamList;//": "节点1"


// 0，模板一，带标题的图文，interfaceRetList，  当interfaceRetList和inputContentList都为空时，作为普通富文本消息处理，当inputContentList不为空是，用模板二处理
//1：模板二，文字选项(有框和无框居左)， inputContentList
// 2：模板3，不带标题的图文，interfaceRetList
//3：模板4 查看详情(interfaceRetList第一个，有图文+查看详情)，
//4：自定义模板（interfaceRetList第一个的title和外部answerStrip(未结束remindQuestion)）
// 99:自定义模板 （interfaceRetList第一个的tempStr和外部answerStrip(未结束remindQuestion)）
// templateid为空：inputContentList和interfaceRetList都为空显示4自定义模板的样式，任意一个不为空，显示1 模板二，文字选项(有框和无框居左)
@property (nonatomic,strong) NSMutableArray   *interfaceRetList;// 问题列表
@property (nonatomic,assign) int   curShowCount;// 当前显示的总数，默认显示9条



// 小程序
@property(nonatomic,copy) NSString *appId;//": "wx3173b4df42371aa6",
@property(nonatomic,copy) NSString *pagepath;//": "pages/shop/shop.html?fissionLevel=oguD05ZFHAG063-PYL6Cb-Cd5vnI&kUuidfrom=oguD05ZFHAG063-PYL6Cb-Cd5vnI",
@property(nonatomic,copy) NSString *thumbUrl;//"https://img.sobot.com/xxx.jpg",
@property(nonatomic,copy) NSString *title;
@property(nonatomic,copy) NSString *logo;//": "临时文案"
@property(nonatomic,copy) NSString *describe;//": "临时文案"

// 文章
@property(nonatomic,copy) NSString *desc;//": "简介，只有纯文字",
@property(nonatomic,copy) NSString *richMoreUrl;//": "https://test.sobot.com/chat-web/user/chatByMsgId?cid=8f88d5660fe546318372f841dac6abc7&msgId=f10cc68e1c944e0faf87d0eb686a7d91&uid=aae384d84ce54d02bf96aaf861aaf18d",
@property(nonatomic,copy) NSString *snapshot;//": "头图",
@property(nonatomic,copy) NSString *content;//": "临时文案"
@property(nonatomic,copy) NSString *articleBody;//": "临时文案"

@property(nonatomic,assign) int clickFlag;//": "临时文案"

@property(nonatomic,assign) int showLinkStyle;
@property(nonatomic,copy) NSString *retErrorMsg;

// 位置 type = 2
@property(nonatomic,copy) NSString *picUrl;//": "https://img.sobot.com/console/common/res/sdk_default_location.jpg",
@property(nonatomic,copy) NSString *lng;//": "116.353276",
//@property(nonatomic,copy) NSString *title;//": "云景四季餐厅",
@property(nonatomic,copy) NSString *url;//": "https://ditu.amap.com/regeo?lng=116.353276&lat=40.001693&src=uriapi&callnative=1&name=云景四季餐厅",
@property(nonatomic,copy) NSString *lat;//": "40.001693",
//@property(nonatomic,copy) NSString *desc;//": "云景四季餐厅"

// 订单卡片 type =4
@property(nonatomic,copy) NSString *orderUrl;//": "https://www.sobot.com",
@property(nonatomic,copy) NSString *createTimeFormat;//": "2022-09-24 17:05:21",
@property(nonatomic,copy) NSString *goodsCount;//": 2,
@property(nonatomic,copy) NSString *createTime;//": 1664010321113,
@property(nonatomic,copy) NSString *statusCustom;//": "不一样的烟火",
@property(nonatomic,copy) NSString *totalFee;//": 881,

//[{"pictureUrl": "xxx.png","name": "商品名称"}],
@property(nonatomic,copy) NSArray *goods;//":
@property(nonatomic,copy) NSString *orderStatus;//": 0,
@property(nonatomic,copy) NSString *orderCode;//": "1000234242342345"

// 商品卡片，type=3
@property(nonatomic,copy) NSString *thumbnail;//": "png",
//@property(nonatomic,copy) NSString *description;//": ",
@property(nonatomic,copy) NSString *label;//": "标签1111",
//@property(nonatomic,copy) NSString *title;//": "标题标题标题标题标题标题",
//@property(nonatomic,copy) NSString *url;//"


-(NSString *)getRequestText:(NSDictionary *)dic;

-(NSString *)getQuestion:(NSDictionary *)dic;


@end


@interface SobotChatRobotAnswerContent : SobotBaseEntity

// 常见问题start
@property (nonatomic,strong) NSArray  *showFaqDocRespVos;
@property (nonatomic,strong) NSArray  *faqDocRespVos;
@property (nonatomic,strong) NSArray  *businessLineRespVos;
@property (nonatomic,strong) NSArray  *groupRespVos;
@property (nonatomic,assign) int showType;//": 0,
@property (nonatomic,assign) BOOL next;//": 0,
// 如果有分页，当前第几页，写死每页5个
@property (nonatomic,assign) int curFaqPage;//": 0,
@property (nonatomic,assign) int curBusinessPage;//": 0,
@property (nonatomic,assign) int curGroupPage;//": 0,
@property (nonatomic,strong  ) NSString     *showName;//": "",
@property (nonatomic,strong  ) NSString     *guideWords;//": "",
@property (nonatomic,assign  ) int     guidePageCount;//": 0,
@property (nonatomic,strong  ) NSString     *templateId;//": "",
@property (nonatomic,strong  ) NSString     *templateName;//": "",
@property (nonatomic,strong  ) NSString     *sort;//": 0,
@property (nonatomic,strong  ) NSString     *model;//": 0,
@property (nonatomic,strong  ) NSString     *imgUrl;//": "",
@property (nonatomic,strong  ) NSString     *receiveRobot;//": "",
@property (nonatomic,assign) int status;//": 0,
// 常见问题end


@property (nonatomic,strong  ) NSString     *guide;//": null,
@property (nonatomic,strong  ) NSString     *answerStrip;//": null,
@property (nonatomic,strong) NSMutableArray  * sugguestions;//": null,
/**
 *  1 直接回答，2 理解回答，3 不能回答, 4引导回答，6互联网寒暄，
 *  7 私有寒暄（包括第三方天气、快递接口）,8百科, 9 向导回答,10 业务接口    // 151 152 153 待接口 多轮会话的类型,1525 多轮触发留言
 */
@property (nonatomic,assign) int answerType; //
@property (nonatomic,strong  ) NSString     *stripe;//": null,
@property (nonatomic,strong) NSMutableArray  * suggestionList;//": null,
@property (nonatomic,strong  ) NSString         *question;//": null,
@property (nonatomic,strong  ) NSString         *time;//": null,
@property (nonatomic,strong  ) NSString         *docId;//": "884e2243ec374410964980f52c050b17",
@property (nonatomic,strong  ) NSString         *docName;//": "多消息样式V6",
@property (nonatomic,strong  ) NSString         *msgTransfer;//": null,
@property (nonatomic,strong  ) NSString         *msgId;//": "b9ed6e8aac2f489e9e7f123f78702efe",


@property (nonatomic,strong  ) NSDictionary     *keywordVo;//": null,
// 转人工提示语
@property (nonatomic,strong) NSString  *tipsMessage;

/**keyword:命中的关键字
 **/
@property (nonatomic,copy) NSString * groupId;
@property (nonatomic,copy) NSString * keywordId;
@property (nonatomic,copy) NSString * keyword;
/**
 *
 *    groupList:选择技能组列表，模型：[{groupId：技能组id，groupName:技能组名称}，……]
 *
 **/
@property (nonatomic,strong) NSMutableArray * groupList;

/**
 *
 *  queueFlag  排队方式标记  只在关键字转人工的时候传给服务端，其他情况传空
 *  1:展示排队或者客服不在线提示，为0不展示(如果转人工失败显示机器人回复，如果成功，不显示机器人回复)
 *
 **/
@property (nonatomic,assign)  int queueFlag;

// 1-客服在线可以转入，0-客服忙碌或不在线，不能转入
@property (nonatomic,assign) int  onlineFlag;

// 转人工提示语
@property (nonatomic,strong) NSString  *transferTips;


/**
 *
 *   transferFlag:1-指定技能组接入，2-选择技能组列表，3-直接转入;
 *
 **/
@property (nonatomic,assign) int  transferFlag;

/**
 *
 *  transferType  转人工类型，0-不转，1-重复提问转人工，2-情绪负向转人工  3、关键词转人工、4、多次命中转人工(显示转人工按钮，不主动转人工)，5:机器人自动转人工(新版拆分为6-9,activeTransfer此时为1) 6直接转人工，7理解转人工，8引导转人工，9未知转人工 10，点踩转人工
 **/
@property (nonatomic,assign  ) int         transferType;//": 1,
@property (nonatomic,assign  ) int         guideGroupFlag;//": null,
@property (nonatomic,assign  ) int         guideGroupNum;//": null,

// 当前显示页数，从0开始
@property (nonatomic,assign  ) int              guideGroupPage;
// 客户原始提问 用于接下来针对词条点赞点踩用，点踩/赞时需要记录用户的原始问题用于统计展示
@property (nonatomic,strong  ) NSString         *originQuestion;//": "多消息样式V6",

@property (nonatomic,strong  ) NSString         *desensitizationWord;//": null
@property (nonatomic,strong  ) NSString         *sensitiveWord;//": null

@property (nonatomic,strong  ) NSString         *answerId;//": "19bb0437e7d54a739e4abcf61399383c",
@property (nonatomic,strong  ) NSString         *ruleId;//": null,
@property (nonatomic,strong  ) NSString         *kbId;//": "3",
@property (nonatomic,strong  ) NSString         *kbName;//": "小智机器人-3"

@end


@interface SobotChatContent : SobotBaseEntity

// msgType =0/1，图片和文本
@property(nonatomic,copy) NSString *content;

/**
 语音翻译
 */
@property(nonatomic,strong) NSString  *msgtranslation;
@property(nonatomic,copy) NSString *duration;
@property(nonatomic,copy) NSString *fileName;
@property(nonatomic,copy) NSString *url;
@property(nonatomic,copy) NSString *fileSize;
@property(nonatomic,copy) NSString *snapshot;

@property(nonatomic,copy) NSString *richmoreurl;

// 文件
@property(nonatomic,copy) NSString *coverUrl;//": "",
//@property(nonatomic,copy) NSString *fileName;//": "\r\n\tces.txt",
//@property(nonatomic,copy) NSString *size;//": 0,
//@property(nonatomic,copy) NSString *fileSize;//": "0 KB",
//@property(nonatomic,copy) NSString *type;//": 7,
//@property(nonatomic,copy) NSString *url;//

//msgType==5,type=0富文本，1多伦，6微信小程序，17文章
@property(nonatomic,assign) SobotMessageRichJsonType type;//": 0,
// msgType=5,type =0
@property(nonatomic,copy) NSMutableArray *richList;

//msgType=5,type!=0
@property(nonatomic,strong) SobotChatRichContent *richContent;
// 文件类型,或富文本时，消息类型
@property(nonatomic,assign) SobotMessageFileType fileType;


// 未格式化的文件大小
@property(nonatomic,assign) int size;

@end


@interface SobotChatMessage : SobotBaseEntity

// 消息类型
@property(nonatomic,assign) SobotMessageType msgType;

@property(nonatomic,copy) NSString *sensitiveWord;
@property(nonatomic,strong) SobotChatContent *richModel;
@property(nonatomic,strong) SobotChatRobotAnswerContent *robotAnswer;



/**
 *  会话时间
 */
@property (nonatomic , strong) NSString *date;

/**
 * 消息id
 */
@property (nonatomic , strong) NSString *msgId;
@property (nonatomic , strong) NSString *revokeMsgId;


/**
 *  内容[未使用]
 */
@property (nonatomic , strong) NSString *contentTemp;

/**
 *  会话id
 */
@property (nonatomic , strong) NSString *cid;

/**
 *  用户id
 */
@property (nonatomic , strong) NSString *sender;

/**
 *  用户名称
 */
@property (nonatomic , strong) NSString *senderName;

/**
 *  发送,0，自己，1机器人，2客服
 */
@property (nonatomic , assign) int      senderType;

/**
 *  会话类型0，不知道怎么用
 */
@property (nonatomic , assign) SobotMessageActionType action;
// 提示语
@property (nonatomic,strong) NSString  *tipsMessage;

/**
 *  头像
 */
@property (nonatomic , strong) NSString *senderFace;


@property (nonatomic , strong) NSString *servant;//": "robot",
// 当是快捷菜单发送的消息时，此处为展示的名称
@property (nonatomic , strong) NSString *servantName;//
@property (nonatomic , assign) int servantType;//": 1,
@property (nonatomic , strong) NSString *servantFace;


/**
 *  发送时间戳 -long
 */
@property (nonatomic , strong) NSString *t;

/**
 *  发送时间
 */
@property (nonatomic , strong) NSString *ts;

/**
 *  客服ID
 */
@property (nonatomic , strong) NSString *receiver;

/**
 *  客服名称
 */
@property (nonatomic , strong) NSString *receiverName;

/**
 *  下线类型
 */
@property (nonatomic , strong) NSString *offlineType;

/**
 *  客服头像
 */
@property (nonatomic , strong) NSString *receiverFace;

/**
 *  是否已读
 */
@property (nonatomic , assign) BOOL isRead;

/**
 *  上传进度
 */
@property (nonatomic , assign) float progress;

/**
 *  发送状态，1 开始发送，2发送失败，0，发送完成
 */
@property (nonatomic , assign) int  sendStatus;


/// 发送人是否包含敏感词,0不启动，1启动，2拒绝
@property (nonatomic , assign) int includeSensitive;

/// 如果触发敏感信息，是否展示所有信息，默认收起
@property (nonatomic , assign) BOOL showAllMessage;
// 敏感词提示语
@property (nonatomic , strong) NSString *sentisiveExplain;

/**
 *  是否播放
 */
@property (nonatomic , assign) BOOL isPlaying;

/**
 *  是否是历史消息
 */
@property (nonatomic , assign) BOOL isHistory;


/**
 机器人评价
 0，不处理，1新添加(可赞、可踩)，2已赞，3已踩，4 超时下线之后不能在评价 置灰并给提示“会话结束，无法反馈”
 */
@property (nonatomic , assign) int commentType;


/**
 机器人显示转人工按钮
 YES 显示，NO不显示
 */
@property (nonatomic , assign) BOOL showTurnUser;


/**
 *  0 没有评价 1已解决  2未解决
 *
 */
@property (nonatomic , assign) int  satisfactionCommtType;

/**
 *
 *  评价后的星级
 */
@property (nonatomic , assign) float  ratingCount;

/**
 *  评价是否开启 已解决 未解决   1开启 0关闭
 */
@property (nonatomic , strong) NSString* isQuestionFlag;

/**
 *
 *   用户发消息 判定是否是被超时下线，如果超时下线不在执行关键字转人工
 *
 **/
@property (nonatomic,assign) BOOL userOffline;


/**
 *
 *   revokeFlag  0    1 撤回 “显示 客服xxx 撤回了一条消息”
 *
 **/
@property (nonatomic,assign) BOOL revokeFlag;



/**
 *
 *  记录通告是否展开
 *
 **/
@property (nonatomic,assign) BOOL isOpenNotice;

/**
 *
 *  消息体中包含leaveMsgFlag=1，表示该消息为离线留言消息，需要在左侧有小图标
 *
 **/
@property (nonatomic,assign) int leaveMsgFlag;

/**
 *  是否是机器人引导语
 */
@property (nonatomic , assign) BOOL isRobotGuide;


// 是否显示发送者信息
@property (nonatomic , assign) BOOL isShowSenderFlag;

@property (nonatomic,strong) NSMutableAttributedString         * _Nullable displayMsgAttr;
@property (nonatomic,strong) NSMutableAttributedString         * _Nullable displaySugestionattr;


// 保证使用时不创建NSMutableAttributedString属性
-(NSString *) getModelDisplayText;
-(NSString *) getModelDisplayText:(BOOL) createAttr;

// 保证使用时不创建NSMutableAttributedString属性
-(NSString *) getModelDisplaySugestionText;
-(NSString *) getModelDisplaySugestionText:(BOOL) createAttr;

- (NSString *)getHtmlAttrStringWithText:(NSString *)text;
@end




NS_ASSUME_NONNULL_END
