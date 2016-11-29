//
//  XYMenuView.h
//  XYMenuView
//
//  Created by mofeini on 16/11/15.
//  Copyright © 2016年 com.test.demo. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, XYMenuViewBtnType) {
    XYMenuViewBtnTypeFastExport = 0, // 快速导出
    XYMenuViewBtnTypeHDExport,       // 高清导出
    XYMenuViewBtnTypeSuperClear,     // 高清导出
    XYMenuViewBtnTypeCancel,         // 取消
};

typedef NS_ENUM(NSInteger, XYMenuViewStyle) {
    XYMenuViewStyleHorizontal = 0,   // 横向
    XYMenuViewStyleVertical          // 竖向
};

NS_ASSUME_NONNULL_BEGIN
@interface XYMenuView : UIView
/** 每个按钮的高度 **/
@property (nonatomic, assign) CGFloat itemHeight;
/** 分割符的颜色 **/
@property (nonatomic, strong) UIColor *separatorColor;
/** 蒙板的透明度 , 默认为0.08*/
@property (nonatomic, assign) CGFloat maskAlpha;
@property (nonatomic, assign) XYMenuViewStyle menuViewStyle;
@property (nonatomic, strong) UIColor *itemBackGroundColor;
@property (nonatomic, strong) UIColor *itemTitleColor;

/**
 * @explain 添加当前弹框菜单view到你的视图上
 *
 * @param   superView  当前view会成为superView的子控件
 * @return  XYMenuView实例化的对象
 */
+ (instancetype)menuViewToSuperView:(UIView *)superView;

- (void)showMenuView;
- (void)dismissMenuView;
- (void)showMenuView:(nullable void(^)())block;
- (void)dismissMenuView:(nullable void(^)())block;
- (void)setItemBackGroundColor:(UIColor * _Nonnull)itemBackGroundColor titleColor:(UIColor *)titleColor forState:(UIControlState)state;
/**
 * @explain 点击menuView上不同类型按钮的事件回调
 *
 * type  不同类型按钮
 */
@property (nonatomic, copy) void (^menuViewClickBlock)(XYMenuViewBtnType type);
@property (nonatomic, copy) void (^hiddenCompletionBlock)();
@end
NS_ASSUME_NONNULL_END
