import http from "http";

const server = http.createServer((req, res) => {
	res.end("Hello from Node!");
});

const PORT = 5000;

server.listen(PORT, () => {
	console.log("Server running on port 5000");
});