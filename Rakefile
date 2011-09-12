# Rakefile stolen and modified from https://github.com/pivotal/cedar/blob/master/Rakefile

require 'rubygems'
require 'tmpdir'

PROJECT_NAME = "DKFile"
CONFIGURATION = "Debug"
UI_SPECS_TARGET_NAME = "Specs"
SDK_DIR = "/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator4.3.sdk"
BUILD_DIR = File.join(File.dirname(__FILE__), "build")

def build_dir(effective_platform_name)
  File.join(BUILD_DIR, CONFIGURATION + effective_platform_name)
end

def system_or_exit(cmd, stdout = nil)
  puts "Executing #{cmd}"
  cmd += " >#{stdout}" if stdout
  system(cmd) or raise "******** Build failed ********"
end

def output_file(target)
  output_dir = if ENV['IS_CI_BOX']
                 ENV['CC_BUILD_ARTIFACTS']
               else
                 Dir.mkdir(BUILD_DIR) unless File.exists?(BUILD_DIR)
                 BUILD_DIR
               end

  output_file = File.join(output_dir, "#{target}.output")
  puts "Output: #{output_file}"
  output_file
end

task :docs do
  puts "-- Removing existing documentation"
  `rm -rf Documentation`
  `mkdir Documentation`

  puts "-- Generating new documentation"
  command = %{appledoc --project-name DKFile --project-company DiscoKit --output Documentation/ --templates "#{ENV['APPLEDOC_TEMPLATE_PATH']}" --keep-intermediate-files Classes}
  puts command
  puts `#{command}`
end

task :cruise do
  Rake::Task[:clean].invoke
  Rake::Task[:build_uispecs].invoke
  Rake::Task[:specs].invoke
  Rake::Task[:uispecs].invoke
end

task :trim_whitespace do
  system_or_exit(%Q[git status --short | awk '{if ($1 != "D" && $1 != "R") print $2}' | grep -e '.*\.[mh]$' | xargs sed -i '' -e 's//    /g;s/ *$//g;'])
end

task :clean do
  system_or_exit(%Q[xcodebuild -project #{PROJECT_NAME}.xcodeproj -alltargets -configuration #{CONFIGURATION} clean SYMROOT=#{BUILD_DIR}], output_file("clean"))
end

task :build_uispecs do
  `osascript -e 'tell application "iPhone Simulator" to quit'`
  system_or_exit(%Q[xcodebuild -project #{PROJECT_NAME}.xcodeproj -target #{UI_SPECS_TARGET_NAME} -configuration #{CONFIGURATION} -sdk "#{SDK_DIR}" build], output_file("uispecs"))
end

task :uispecs => :build_uispecs do
  ENV["DYLD_ROOT_PATH"] = SDK_DIR
  ENV["IPHONE_SIMULATOR_ROOT"] = SDK_DIR
  ENV["CFFIXED_USER_HOME"] = Dir.tmpdir
  ENV["CEDAR_HEADLESS_SPECS"] = "1"
  ENV["CEDAR_REPORTER_CLASS"] = "CDRColorizedReporter"

  system_or_exit(%Q[#{File.join(build_dir("-iphonesimulator"), "#{UI_SPECS_TARGET_NAME}.app", UI_SPECS_TARGET_NAME)} -RegisterForSystemEvents]);
end

task :default => :cruise
