file hydro.elf
set sysroot
set architecture arm
target remote localhost:3333
monitor reset halt
load

# For Imp Testing 
#set pagination off
#b evs.cpp:308
#set $c = 0
#c
#while($c < 100)
#  set $c = $c + 1
#  p data[lt_v] 
#  p data[lm_v] 
#  p data[rt_v] 
#  p data[rm_v] 
#  p ltlm
#  p rmlm
#  p rtrm
#  c
#end


# For Memory Testing
#b LTC2654.cpp:26
#b file::~file
#set $c = 0
#c
#
#while($c < 10)
#  set $c = $c + 1
#  p/x data
#  c
#end
#
#d 1 
