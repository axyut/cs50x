function calculate() {
	// Get the values and operation from the form
	var value1 = Number(document.getElementById("value1").value);
	var value2 = Number(document.getElementById("value2").value);
	var operation = document.getElementById("operation").value;

	// Perform the calculation
	var result;
	switch (operation) {
		case "add":
			result = value1 + value2;
			break;
		case "subtract":
			result = value1 - value2;
			break;
		case "multiply":
			result = value1 * value2;
			break;
		case "divide":
			result = value1 / value2;
			break;
	}

	// Display the result
	alert("Result: " + result);
}
