//
//  SCLockFileUtilities.h
//  SelfControl
//
//  Created by Charles Stigler on 20/10/2018.
//

#import <Foundation/Foundation.h>
#import "SelfControlCommon.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCSettings : NSObject

@property (readonly) uid_t userId;
@property (readonly) NSDictionary* dictionaryRepresentation;
@property (nonatomic, readonly, getter=isReadOnly) BOOL readOnly;

@property (class, nonatomic, readonly) NSString* settingsFileName;
@property (class, nonatomic, readonly) NSString* securedSettingsFilePath;

+ (instancetype)sharedSettings;

- (void)reloadSettings;
- (void)writeSettingsWithCompletion:(nullable void(^)(NSError* _Nullable))completionBlock;
- (void)writeSettings;
- (void)synchronizeSettingsWithCompletion:(nullable void(^)(NSError* _Nullable))completionBlock;
- (void)synchronizeSettings;

- (void)setValue:(id)value forKey:(NSString*)key stopPropagation:(BOOL)stopPropagation;
- (void)setValue:(nullable id)value forKey:(NSString*)key;

- (id)valueForKey:(NSString*)key;
- (BOOL)boolForKey:(NSString*)key;

- (void)resetAllSettingsToDefaults;

@end

NS_ASSUME_NONNULL_END
