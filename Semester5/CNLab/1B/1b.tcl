set ns [new Simulator]
set nf [open 1b.nam w]
$ns namtrace-all $nf
set nd [open 1b.tr w]
$ns trace-all $nd

proc finish { } {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam 1b.nam &
exit 0
}

#creating the nodes and setting the links

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 1Mb 20ms DropTail
$ns duplex-link $n1 $n2 512Kb 20ms DropTail
$ns queue-limit $n1 $n2 5

# creating various agents and attaching them with nodes
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set sink [new Agent/Null]
$ns attach-agent $n2 $sink
$ns connect $udp0 $sink

$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run
