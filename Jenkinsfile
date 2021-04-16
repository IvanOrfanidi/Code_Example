pipeline {
    agent any
    stages {

        stage('build') {
            steps {
                sh 'bash compile.sh'
            }
        }

        stage('cppcheck') {
            steps {
                sh 'cppcheck --language=c++ --enable=all --xml --xml-version=2 -i ext color_modifier is_stl_container move_semantics thread_safe_queue type_index wait_time_period 2> build/cppcheck.xml'
                sh 'cppcheck-htmlreport --source-encoding="iso8859-1" --title="project" --source-dir=. --report-dir=build --file=build/cppcheck.xml'
                publishHTML(
                    target: [
                      allowMissing: true,
                      alwaysLinkToLastBuild: false,
                      keepAll: false,
                      reportDir: 'build',
                      reportFiles: 'index.html',
                      reportName: 'CppCheck Report',
                      reportTitles: ''
                    ]
                )
            }
        }

        stage('clean') {
            steps {
                cleanWs()
            }
        }
    }
}
