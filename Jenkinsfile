pipeline {
	agent any
 	stages {
        	stage('Build') { 
            		steps { 
                		sh 'make' 
            		}
        	}
	}
	post {
	  	success {
	    		sh "echo 'Success'"
	  	}
	  	failure {
	    		sh "echo 'Failure'"
          	}
        }		
}
