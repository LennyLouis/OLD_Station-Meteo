var thermometre = angular.module("thermometre", ['angular-svg-round-progressbar']);

thermometre.controller('ChaleurController', function ChaleurController($scope, $http, $interval) {
		
		/*$scope.temperature = [{
			"piece":"Erreur",
			"temperature":"-1"
		}];*/
	
	$scope.temperature = [
		{
			piece: 'Salon',
			temperature: '21'
		}, {
			piece: 'Chambre 1',
			temperature: '23'
		}, {
			piece: 'Chambre 2',
			temperature: '20'
		}, {
			piece: 'Cuisine',
			temperature: '19'
		}, {
			piece: 'Garage',
			temperature: '12'
		}
	];
	
	$scope.reload = function () {
        $http({
		  method: 'GET',
		  url: './api/api.php'
		}).then(function (success){
			  $scope.temperature = success.data;
			console.log(success.data);
		},function (error){
			console.log('Error');
	   });
		$scope.date = new Date(); // EEEE d MMMM y
    };
    $scope.reload();
    $interval($scope.reload, 1000);
	
});