<?php
session_start();

if (!isset($_SESSION['user'])) {
    echo "Unauthorized access!";
    exit;
}

$syscall = $_POST['syscall'];
$user = $_SESSION['user'];
$timestamp = date("[D M d H:i:s Y]");
$logFile = "syscall.log";

if (!file_exists($logFile)) {
    file_put_contents($logFile, "");
}

if ($syscall == "open") {
    file_put_contents($logFile, "$timestamp User: $user - SUCCESS open()\n", FILE_APPEND);
    echo "✅ File opened successfully.";
} else if ($syscall == "fork") {
    if ($user == "admin") {
        file_put_contents($logFile, "$timestamp User: $user - SUCCESS fork()\n", FILE_APPEND);
        echo "✅ Fork process executed.";
    } else {
        file_put_contents($logFile, "$timestamp User: $user - DENIED fork()\n", FILE_APPEND);
        echo "❌ Fork operation denied.";
    }
} else {
    echo "Invalid syscall.";
}
?>
