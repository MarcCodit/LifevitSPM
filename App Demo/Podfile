# Uncomment this line to define a global platform for your project
 platform :ios, '12.0'

#project 'LifevitSDK/LifevitSDK'
source 'https://github.com/CocoaPods/Specs.git'

def shared_pods
use_frameworks!
pod 'Charts'
pod 'ChartsRealm'
end

target "LifevitSDKSample" do
    shared_pods
end

post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['SWIFT_VERSION'] = '4.2'
    end
  end
end