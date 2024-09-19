var autoRefresh = true;
var intervalId;

function toggleHistorial() {
    var historialDiv = document.getElementById('historial');
    if (historialDiv.style.display === 'none') {
        historialDiv.style.display = 'block';
        clearInterval(intervalId); // Stop the auto-refresh
        autoRefresh = false;
    } else {
        historialDiv.style.display = 'none';
        autoRefresh = true;
        startAutoRefresh(); // Restart the auto-refresh
    }
}