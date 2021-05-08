# Mask Credit Card Numbers

- if credit card number length is less than 6 characters, don't mask
- dont mask the first character
- dont mask the last 4 character
- mask only digits

Samples are

|type| input   |      output      |
|--|----------|-------------|
|short| 54321 |54321 |
|basic| 5512103073210694 |    5###########0694   |
|dashed| 4556-3646-0793-5616 | 4###-####-####-5616 |
|11 digits|64607935616|6######5616|
|all letters|ABCD-EFGH-IJKLM-NOPQ|ABCD-EFGH-IJKLM-NOPQ|
|mixed|A1234567BCDEFG89HI|A#######BCDEFG89HI|