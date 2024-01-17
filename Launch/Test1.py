import rclpy
from std_msgs.msg import String

def callback(msg):
    print(f"Received: {msg.data}")

def simple_publisher():
    rclpy.init()

    node = rclpy.create_node('simple_publisher_node')

    publisher = node.create_publisher(String, 'chatter', 10)
    timer_period = 1  # seconds
    timer = node.create_timer(timer_period, lambda: publish_message(publisher))

    subscription = node.create_subscription(String, 'chatter', callback, 10)

    print("Simple ROS 2 Publisher Node")

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

def publish_message(publisher):
    msg = String()
    msg.data = "Hello, ROS 2!"
    publisher.publish(msg)

if __name__ == '__main__':
    simple_publisher()
