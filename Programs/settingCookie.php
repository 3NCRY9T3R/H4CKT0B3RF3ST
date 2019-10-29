<?php
//in this we have set cookie with the name of username submitted :)
if(isset($_POST["submit"]))
{
    $c_name="testing_cookie";
    $c_content="content 1111";
    $c_expiration=time()+(60*60*24*7);
    $setcookie=setcookie($c_name,$c_content,$c_expiration);
    if($setcookie)
        echo "your cookie with cookie name( ".$c_name." ) is set";
    
}
?>
<!doctype html>
    <body>
    <form action="cookies.php" method="post">
        <input type="text"  name="username" placeholder="enter cookie content here">
       <!-- <input type="password" name="password" placeholder="enter password ">-->
        <button name="submit">submit</button>
        </form>
    </body>
</html>
