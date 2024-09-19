<?php
$hostname = "localhost"; 
$username = "root"; 
$password = ""; 
$database = "sensor_db"; 

$conn = mysqli_connect($hostname, $username, $password, $database, 3306);

if (!$conn) { 
    die("Connection failed: " . mysqli_connect_error()); 
} 
?>