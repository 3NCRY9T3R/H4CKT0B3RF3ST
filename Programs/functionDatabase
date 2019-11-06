<?php
//in this we are going to use almost all function used for database operations
//just download the file and avail the benefit
//here localhost-serverName
//root-userName of database
//test-databaseName
$connect=mysqli_connect("localhost","root","","test");
if(!$connect){
    die("database connection failed");
}
function sendingData()
{
    //in this we are sending data to database
    $username=$_POST["username"];
    
    $password=$_POST["password"];
    
    if($username && $password)
    {
        //connecting database
        $connect=mysqli_connect("localhost","root","","test");
        if($connect)
        {
            echo "going well";
        }
        //creating query
        $query="INSERT INTO user(username,password) VALUES ('$username','$password')";
        //sending query
        $test=mysqli_query($connect,$query);
        if(!$test)
        {
            die("query failed".mysqli_error());
        }
       
    }
    
}

function showData()
{
//displaying data from database
    global $connect;
        $query="select * from user";
        //sending query
        $test=mysqli_query($connect,$query);
        if(!$test)
        {
            die("query failed".mysqli_error());
        }
        echo ""."<br>";
        while($row=mysqli_fetch_assoc($test))
                {
                     //choosing id from assoc array
                    $id=$row['id'];
                    echo "<option>$id</option>";
                }
}
function readData()
{
//reading the data
    global $connect;
     $query="select * from user";
        //sending query
        $test=mysqli_query($connect,$query);
        if(!$test)
        {
            die("query failed".mysqli_error());
        }
      echo ""."<br>";

      while($row=mysqli_fetch_assoc($test))
      {
            print_r($row);
      }
}
function updateData(){
//updating the data base
    global $connect;
    $username=$_POST['username'];
    $password=$_POST['password'];
    $id=$_POST['id'];
        $query="update user set username='$username' , password='$password' where id='$id'";
        //sending query
        $test=mysqli_query($connect,$query);
    if(!$test)
        die("error");
}
function deleteData(){
    //performing a delete operation in database
    global $connect;
    $username=$_POST['username'];
    $password=$_POST['password'];
    $id=$_POST['id'];
        $query="delete from user where id='$id'";
        //sending query
        $test=mysqli_query($connect,$query);
    if(!$test)
        die("error");
}
?>
