<?php
session_start();

$username = $_POST['username'];
$password = $_POST['password'];
$valid = false;

$file = fopen("users.txt", "r");
while (($line = fgets($file)) !== false) {
    list($user, $pass) = explode(" ", trim($line));
    if ($user == $username && $pass == $password) {
        $_SESSION['user'] = $username;
        $valid = true;
        break;
    }
}
fclose($file);

if ($valid) {
    header("Location: dashboard.html");
} else {
    echo "Invalid credentials. <a href='index.html'>Try again</a>";
}
?>
