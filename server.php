<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Handle POST request
    $name = $_POST['name'];
    $message = "Hello, $name! This is the server responding.";

    // Respond with a JSON object
    header('Content-Type: application/json');
    echo json_encode(['message' => $message]);
} else {
    // Handle other HTTP methods (e.g., GET)
    http_response_code(405); // Method Not Allowed
}
?>
