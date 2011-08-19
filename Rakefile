require 'rubygems'

task :docs do

  puts "-- Removing existing documentation"
  `rm -rf Documentation`
  `mkdir Documentation`

  puts "-- Generating new documentation"
  command = %{appledoc --project-name DKFile --project-company DiscoKit --output Documentation/ --templates "#{ENV['APPLEDOC_TEMPLATE_PATH']}" --keep-intermediate-files Classes}
  puts command
  puts `#{command}`

end

task :default => :docs
