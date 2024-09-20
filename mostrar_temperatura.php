<?php
include 'conexion.php';
?>
<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Temperatura Actual</title>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="EstilosMostrarTemperatura.css"> <!-- Enlace al archivo CSS -->
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>

</head>

<body>
    <div class="gradient">
        <?php
        // Realizar consulta SQL para obtener la temperatura más reciente
        $query = "SELECT temperatura, distancia FROM temperaturas ORDER BY fecha_temperatura DESC LIMIT 1";
        $result = mysqli_query($conn, $query);

        echo "<h1>Temperatura Actual</h1>";

        if (mysqli_num_rows($result) > 0) {
            // Imprimir el valor de temperatura si hay resultados
            $row = mysqli_fetch_assoc($result);
            // Obtener la temperatura
            $temperatura = $row["temperatura"];
            $distancia = $row["distancia"];

            // Mostrar la temperatura
            if ($temperatura < 10) {
                echo "<p>La temperatura actual es: " . $temperatura . " °C <img id='icon' src='./img/baja-temperatura.png' alt='Hace frío' style='width: 60px'></p>";
            } elseif ($temperatura >= 10 && $temperatura <= 30) {
                echo "<p>La temperatura actual es: " . $temperatura . " °C <img id='icon' src='./img/aire.png' alt='Temperatura normal' style='width: 60px'></p>";
            } else {
                echo "<p>La temperatura actual es: " . $temperatura . " °C <img id='icon' src='./img/temperatura-alta.png' alt='Temperatura normal' style='width: 60px'></p>";
            }

            echo "<h1>Distancia Actual</h1>";
            echo "<p>distancia " . $distancia . "</p>";
        } else {
            echo "<p>No se encontraron registros.</p>";
        }