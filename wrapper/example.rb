require 'steeringlock'
obj=Steeringlock
obj.s.BatteryValue=4.0
obj.s.UnlockInProcess=1
x=Thread.new { while (1 == 1) do obj.SYS_FUN_iterate; sleep 0.02; end}
