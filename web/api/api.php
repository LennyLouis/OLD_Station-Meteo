<?php


function get_temp($pin) {
	
	$api_key = 'a23584e57c144bbe8d4bcf5633f31576';
	
	$reponse = "-1";
	$ch = curl_init();

	curl_setopt($ch, CURLOPT_URL, 'http://blynk-cloud.com/'.$api_key.'/get/'.$pin);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
	curl_setopt($ch, CURLOPT_HEADER, FALSE);

	$response = curl_exec($ch);
	curl_close($ch);

	//var_dump($response);
	$poubelle = array("[", "]", "\"");
	$response = str_replace($poubelle, "", $response);
	return $response;
}

//function temperature() {
	$arr = array(
		array(
			"id" => "0",
			"piece" => "Sallon",
			"temperature" => get_temp("V0")
		)/*,
		array(
			"id" => "1",
			"piece" => "Cuisine",
			"temperature" => get_temp("V1")
		)/*,
		array(
			"id" => "2",
			"piece" => "Entrée",
			"temperature" => get_temp("V2")
		)*/
	);

echo json_encode($arr);
//}

?>