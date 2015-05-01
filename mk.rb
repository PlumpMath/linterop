#! ruby

# The extension name is hint for the VIM to view the source properly.
# Have a nice day.

require "fileutils"

def target_ide
    if RUBY_PLATFORM =~ /mingw/ then
        return "Visual Studio 11"  # Visual Studio 2o12
    elsif RUBY_PLATFORM =~ /linux/ then
        throw Exception.new("Linux not implemented yet")
    elsif RUBY_PLATFORM =~ /darwin/ then
        return "Xcode"   # Attention not "XCode"
    end
    throw Excetion.new("Dont know what the f*** it is")
end

cur_path = File.absolute_path(__FILE__.encode("UTF-8"))
cur_path = cur_path.chomp(File.basename(cur_path))  #Which ends with a slash
#puts cur_path
build_dir = cur_path + "build"

if File.file? build_dir then
  puts "Target dir \"#{build_dir}\" is a file"
  puts "program aborted"
  exit 1
end

if not File.directory? build_dir then
  puts "Making #{build_dir}"
  FileUtils.mkdir_p build_dir
end

if not File.directory? build_dir then 
  puts "#{build_dir} is not there"
  puts "program aborted"
  exit 1
end

Dir.chdir build_dir

cmd = "cmake -G \"#{target_ide}\" .."
if not system cmd then
 puts "Failed to build project"
 exit 1
end

puts "Generated"










