<?php
echo "hello here we are going to print star pattern in decreasing pyramid";
 $h=15;//declaring variables
echo $h;
echo "<br>";
for($h;$h>0;$h--)
{
    
    for($j=0;$j<$h-1;$j++) 
    {
        echo "*"; //printing star
        echo " ";
    }
    echo "<br>"; //printing in new line
    
 }
 ?>
