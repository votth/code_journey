# internet
- connection of lots of networks

## routers
- route-er

## TCP/IP protocols
- set of rules
### IP
- addresses: #.#.#.#
### TCP
- type of service / port
- packets, ordered number
- if missing any parts, resend
### UDP
- doesn't have gurantee sending
- for video call and video streaming etc.

## domain name system - DNS
- translate domain names to IP addresses

# HTTP - HTTPS
- https://www.example.com/\<path\>
	- www.example.com
		- www: sub domain
		- example.com: domain name
	- com: top-level domain
	- /: root
	- https: protocol

## GET - POST
- request - response
- status code, content-type / mime-types
	- 200, 301, 404 etc.
	- 418 I'm a Teapot
- http://safetyschool.org

## curl
``` bash
curl -I -X GET http://harvard.edu
curl -I -X GET https://www.harvard.edu
```

# HTML
- structure of a page, not really a programmning language
``` bash
http-server
```
- example
- tags/elements and atrributes
``` html
<!DOCTYPE html>

<html>
	<head lang="en">
		<title>hello</title>
	</head>
	<body>
		hello, body
	</body>
</html>
```
- some other tags
	- paragraph: \<p\> \</p\>
	- headings: \<h1\>\</h1\>, \<h2\>\</h2\>, ... \<h6\>\</h6\>
	- list: 
		- unordered: \<ul\> \</ul\>
		- ordered: \<ol\> \</ol\>
		- item: \<li\>\</li\>
	- table
	``` html
	<table>
		<thead>
			<tr>
				<th>Name</th>
				<th>Number</th>
			</tr>
		</thead>
		<tbody>
			<tr>
				<td>Carter</td>
				<td>+6456</td>
			</tr>
		</tbody>
	</table>
	```
	
	- image: \<img alt="atl text" src="path"\>
	- video: 
	``` html
	<video autoplay loop muted width="1280">
		<source src="path" type="video/mp4">
	</video>	
	```
	- iframe: \<iframe src="link to whatever iframe"\>\<iframe\>
	- links:
		- \<a href="https://www.example.com/"\>example\</a\>
		- locale link: href="path"

	- responsiveness
	``` html
	<head>
		<meta name="viewport" content="initial-scale=1, width=device-width">
	</head>
	```

	- search
	``` html
	<body>
		<form action="https://www.google.com/search" method="get">
			<input autocomplete="off" autofocus name="q" placeholer="your search" type="text">
			<input type="submit">
		</form>
	</body>
	```

- validator.w3.org
- html entity &#169
- css

``` html
<head>
	<link href="path/to/css" rel="stylesheet">
	<title>example</title>
</head>

<body class = "entered">
</body>
```

# CSS
- type / . class / # ID / [] attribute selectors
- href= or href\*=

``` css
.centered
{
	text-align: center;
}

header
{
	font-size: large;
}
```

## frameworks
- bootstraps

# DOM - d optic model?
