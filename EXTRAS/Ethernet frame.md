

```
       Ethernet Frame
+--------------------------------------------------------+
|                Ethernet Header                         |
+---------------------------+----------------------------+
|    Source MAC Address     |   Destination MAC Address  |
+---------------------------+----------------------------+
|                      EtherType                         |
+--------------------------------------------------------+
|                  IP Packet Header                      |
+--------------------------------------------------------+
|Version| IHL  | DSCP & ECN |       Total Length         |
+-------+------+------------+----------------------------+
|      Identification        |Flags & Fragment Offset    |
+-----------------------------+--------------------------+
|     Time to Live (TTL)     |        Protocol           |
+-----------------------------+--------------------------+
|                   Header Checksum                      |
+--------------------------------------------------------+
|                   Source IP Address                    |
+--------------------------------------------------------+
|                Destination IP Address                  |
+--------------------------------------------------------+
|                TCP/UDP Segment Header                  |
+--------------------------------------------------------+
|   Source Port   |   Destination Port  |    ...         |
+-----------------+---------------------+----------------+
|     Sequence Number            | Acknowledgment Number |
+--------------------------------+-----------------------+
| Data Offset | Reserved |   Flags (Control Bits)        |
+-------------+----------+-------------------------------+
|         Window Size             |       Checksum       |
+-------------------------------+------------------------+
|       Urgent Pointer            |     (Options)        |
+-------------------------------+------------------------+
|                  HTTP Request and Payload              |
|                   Starts Here                          |
+--------------------------------------------------------+

```