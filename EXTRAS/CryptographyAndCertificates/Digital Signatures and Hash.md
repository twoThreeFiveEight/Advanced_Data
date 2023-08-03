
#### Hash
![[Pasted image 20230725114249.png]]


#### Digital Signature
![[Pasted image 20230725131950.png]]


##### Steps
---
1. Bob makes a HASH of the Data he wants to send.
2. He encrypts the HASH using the ***PRIVATE*** Key which creates the Signature.
3. He includes the Data he wishes to send along with the Signed HASH to the client
4. The client uses Bobs ***PUBLIC*** key to to decrypt the Signature to retrieve the original HASH of the data.
5. The client then creates a HASH of the data using the same HASHING algorithm bob used to create his.
6. The client compares the HASH's. If Equal we know the Data was not changed and we know it was signed by Bob because his ***PUBLIC*** key was the only one that could decrypt the Signature therefor verifying the ***Integrity and Authenticity***.

![[Pasted image 20230725132525.png]]