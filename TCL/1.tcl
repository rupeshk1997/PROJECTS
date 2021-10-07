for {set x 2} {$x<100} {incr x} {
    set flag 1
    for {set i 2} {$i<$x} {incr i} {
        set y [expr $x % $i]
        if {$y == 0}  {
            puts "$x: not a prime no"
            set flag 0
            break   
        }
    }

    if {$flag ==1} {
        puts "$x: prime no"
    }
}