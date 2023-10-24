

Pod::Spec.new do |s|

 

  s.name         = "SobotCommon"
  s.version      = "2.1.0"
  s.summary      = "SobotCommon framework"


  s.description  = <<-DESC
  This is the sobot customer service base component integration package
                   DESC

  s.homepage     = "https://github.com/ZCSDK/SobotCommon"
 
  s.license      = "MIT"

  s.author           = { 'zhangxy' => 'app_dev@sobot.com' }

  s.source           = { :git => "https://github.com/ZCSDK/SobotCommon.git", :tag => s.version.to_s }

  s.platform     = :ios, '9.0'

  s.requires_arc = true

# 注意新包去掉了 armv7
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }

  s.ios.vendored_frameworks = 'SobotCommon.framework'

  s.resources = 'SobotCommon.bundle'
end
