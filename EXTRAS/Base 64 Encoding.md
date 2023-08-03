Base64 encoding is a method of converting binary data into an ASCII string format by translating it into a radix-64 representation. The particular set of 64 characters chosen to represent the 64 place-values for the base varies between implementations.

In the context of digital certificates, Base64 encoding is commonly used when displaying certificates and keys in PEM format, which is a de facto standard for "privacy-enhanced mail". PEM is simply Base64 encoded DER, where DER (Distinguished Encoding Rules) is a binary format for data structures described by ASN.1.

When a certificate is Base64 encoded, it allows the certificate to be sent in email, posted in ASCII-friendly environments, or manipulated with text-based tools. Essentially, it's a way to ensure that the binary data of the certificate doesn't get corrupted when being transferred or stored, since binary data can be misinterpreted by systems expecting text.

Base64 encoded certificates often begin with a header line ("-----BEGIN CERTIFICATE-----") and end with a footer line ("-----END CERTIFICATE-----"), so you'll know when you're dealing with this format.

To use a Base64 encoded certificate, it's usually necessary to decode the Base64 encoding to get the original binary data. The software you're using to manage or install the certificate will typically handle this for you.