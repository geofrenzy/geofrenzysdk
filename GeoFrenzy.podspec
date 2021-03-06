#
# Be sure to run `pod lib lint GeoFrenzy.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'GeoFrenzy'
  s.version          = '0.6.3'
  s.summary          = 'GeoFrenzy allows your apps to access the global (.place) geofence registry.'
  s.homepage         = 'https://developer.smartfences.place'
  s.license          = { :type => 'Proprietary', :file => 'LICENSE' }
  s.author           = { 'Ben Tally' => 'ben.tally@geo.network' }
  s.source           = { :git => 'https://github.com/geofrenzy/geofrenzysdk.git', :tag => s.version }
  s.ios.deployment_target = '9.0'
  s.ios.vendored_frameworks = 'GeoFrenzy/Frameworks/GeoFrenzy.framework'
  s.dependency 'Protobuf', '~> 3.5.0'
  s.dependency 'CouchbaseLite'
end
