# ISODE++ 

A modern C++ re/implementation of some ITU-T OSI protocols X Series -- in short, **an OSI stack** -- 
found here: [ITU-T X Series](http://www.itu.int//en/ITU-T/publications/Pages/structure.aspx#X) 
based on the public domain ISODE-8 source code [ISODE](https://en.wikipedia.org/wiki/ISO_Development_Environment)

For an introduction to the OSI model and specifications, see
[OSI model](https://en.wikipedia.org/wiki/OSI_model)

A tribute to   
Marshall T [Rose](https://en.wikipedia.org/wiki/Marshall_Rose)     
Colin [Robbins](https://en.wikipedia.org/wiki/Colin_Robbins_%28software_engineer%29)    
Julian P [Onions](https://en.wikipedia.org/wiki/Nexor#Personnel_and_alumni)     
Steve [Kille](https://en.wikipedia.org/wiki/Steve_Kille)   

Build Status
------------

- Travis: [![Travis Build Status](https://travis-ci.org/kampbell/isode.png?branch=develop)](https://travis-ci.org/kampbell/isode)
- AppVeyor: [![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/7iyrx3f233s3akae)](https://ci.appveyor.com/project/zosrothko/ISODE)

This c++ version is using a FiniteStateMachine to manage the protocol of each OSI layer as described verbatim by the
X.2xx specifications.

Notice: 
On the server/responder side, the OSI stack is build from the TSAP layer up to the AcSAP layer using one dynamic shared module per layer, shared modules that are selected by each corresponding address selectors.

Read the cpp/README for building & testing the ISODE++ stack.

**This is a Work In Progress with numerous bugs, not yet designed areas**  
**Contributions are wellcome.**
