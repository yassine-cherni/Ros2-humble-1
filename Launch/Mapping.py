import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import OccupancyGrid

class MappingNode(Node):
    def __init__(self):
        super().__init__('mapping_node')
        self.subscription = self.create_subscription(
            LaserScan,
            'laser_scan_topic',  # Replace with your laser scan topic
            self.scan_callback,
            10)
        self.publisher = self.create_publisher(
            OccupancyGrid,
            'map_topic',  # Replace with your map topic
            10)

    def scan_callback(self, msg):
        # Process the laser scan data and update the map
        # Implement SLAM algorithms or use existing packages like gmapping

        # Publish the updated map
        map_msg = OccupancyGrid()
        # Populate the map_msg with your map data
        # Set map_msg.header, map_msg.info, and map_msg.data fields accordingly
        self.publisher.publish(map_msg)

def main(args=None):
    rclpy.init(args=args)
    mapping_node = MappingNode()
    rclpy.spin(mapping_node)
    mapping_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
  
