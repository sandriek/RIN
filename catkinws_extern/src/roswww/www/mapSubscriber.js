var ros = new ROSLIB.Ros();	

  // Connecting to ROS
  // -----------------
var ros = new ROSLIB.Ros();
ros.on('error', function(error) {
    document.getElementById('connecting').style.display = 'none';
    document.getElementById('connected').style.display = 'none';
    document.getElementById('closed').style.display = 'none';
    document.getElementById('error').style.display = 'inline';
    console.log(error);
  });

  // Find out exactly when we made a connection.
  ros.on('connection', function() {
    console.log('Connection made!');
    document.getElementById('connecting').style.display = 'none';
    document.getElementById('error').style.display = 'none';
    document.getElementById('closed').style.display = 'none';
    document.getElementById('connected').style.display = 'inline';
  });

  ros.on('close', function() {
    console.log('Connection closed.');
    document.getElementById('connecting').style.display = 'none';
    document.getElementById('connected').style.display = 'none';
    document.getElementById('closed').style.display = 'inline';
  });
// Create a connection to the rosbridge WebSocket server.
  ros.connect('ws://localhost:9090');

function setTopics(nameTopic,name,messageType){
        nameTopic = new ROSLIB.Topic({
        ros : ros,
        name : name,
        messageType : messageType
  });
  return nameTopic;
}
setTopics(this.ros,'/clusterMap','std_msgs/Int32MultiArray').subscribe(function(message) {
	console.log("Received map" + message.data);
});
