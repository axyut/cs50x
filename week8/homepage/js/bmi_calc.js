function calculateBMI() {
	// Get the user's weight and height
	var weight = document.getElementById("weight").value;
	var height = document.getElementById("height").value;

	// Calculate the BMI
	var bmi = (weight / (height / 100)) ^ 2;

	// Display the result
	alert("Your BMI is " + bmi);
}
