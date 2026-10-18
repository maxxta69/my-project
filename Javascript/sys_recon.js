import os from "os";
import { Bytes_to_GB, Bytes_to_MB, Bytes_to_KB } from "./conversions.js";

const hostname = os.hostname();
const platform = os.platform();
const kernel_release = os.release();

const { uid, gid, username, homedir, shell } = os.userInfo();

const total_memory = Bytes_to_MB(os.totalmem());
const free_memory = Bytes_to_MB(os.freemem());

console.log("====== SYSTEM RECONNAISANCE =========\n\n");

console.log("Hostname: ", hostname);
console.log("Platform: ", platform);
console.log("Kernel release: ", kernel_release);
console.log("uid: ", uid);
console.log("gid: ", gid);
console.log("Username: ", username);
console.log("Home directory: ", homedir);
console.log("Shell: ", shell);
console.log("Total Memory(MB): ", total_memory);
console.log("Free memory(MB): ", free_memory);
// const Load_average = os.loadavg();
