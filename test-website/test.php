<?php
$login_name = $_POST["name"];
$login_password = $_POST["password"];

if(!empty($$login_name) && !empty($login_password){
    if($login_name == "admin" && $login_password == "hans123"){
        echo "login correct";
    }
}
?>

<!DOCTYPE html>
<head>
</head>
<body><h1>test page</h1>
    <form action="test.php" method="POST">
    <label>name</label>
    <input type="text" name="name" /><br>
    <label>password</label>
    <input type="text" name="password" />
    <input type="submit" value"send">
</form>
</body>
