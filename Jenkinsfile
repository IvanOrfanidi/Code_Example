pipeline {
    agent any
    stages {

        stage('build') {
            steps {
                sh 'bash compile.sh'
            }
        }

        stage('clean') {
            steps {
                cleanWs()
            }
        }
    }
}
