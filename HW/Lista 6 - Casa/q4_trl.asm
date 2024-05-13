data
  media: .float 14.0


.text

 
li $v0, 6
syscall 

lwc1 $f1, media

sub.s $f0, $f1, $f0

 li $v0, 2
 mov.s $f12, $f0
 syscall