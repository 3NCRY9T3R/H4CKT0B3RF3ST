<?php
echo "Here we are going to create, read and write a file";
echo "<br>"
function file_create()
{
    //in this function we are going to create a file using php
    $file="name.txt";
    $operation=fopen($file,'w');
    fclose($operation);
    
}
function file_write()
{
    //using this function you can write inside a file
     $file="name.txt";
    $file_content="hey this content is written using php"; //content goes here
    if($operation=fopen($file,'w'))
    {
        fwrite($operation,$file_content);
        
    }
    fclose($operation);   
}
function file_read()
{
  //using this function we are going to read inside a file
     $file="name.txt";
    $operation=fopen($file,'r');
    echo fread($operation,filesize($file));
    fclose($operation);
}
//uncomment the below function and see the program running 
//file_create(); 
//file_write();
//file_read();
?>
