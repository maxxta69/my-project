import os from "os";
import { Bytes_to_GB, Bytes_to_MB, Bytes_to_KB } from "./conversions.js";
import { ifError } from "assert/strict";

console.log("====== SYSTEM RECONNAISANCE =========\n\n");

try {
  const hostname = os.hostname();
  console.log("Hostname: ", hostname);
} catch (err) {
  console.error("Something went wrong!", err);
}

try {
  const platform = os.platform();
  console.log("Platform: ", platform);
} catch (err) {
  console.error("Something went wrong!", err);
}

try {
  const kernel_release = os.release();
  console.log("Kernel version: ", kernel_release);
} catch (err) {
  console.error("Something went wrong!", err);
}

try {
  const { uid, gid, username, homedir, shell } = os.userInfo();
  console.log(
    `uid: ${uid}\ngid: ${gid}\nUsername: ${username}\nHome directory: ${homedir}\nShell: ${shell}`,
  );
} catch (err) {
  console.error("Something went wrong!", err);
}

try {
  const total_memory = Bytes_to_MB(os.totalmem());
  const free_memory = Bytes_to_MB(os.freemem());
  console.log("Total Memory(MB): ", total_memory);
  console.log("Free memory: ", free_memory);
} catch (err) {
  console.error("Something went wrong!", err);
}

try {
  const netIntf = os.networkInterfaces();
  for (const name in netIntf) {
    for (const iface of netIntf[name]) {
      if (iface.internal === true || iface.family === "IPv6") break;
      console.log(`Interface: ${name}`);
      console.log(`\nAddress: ${iface.address}`);
      console.log(`\nNetmask: ${iface.netmask}`);
      console.log(`\nMAC: ${iface.mac}`);
    }
  }
} catch (err) {
  console.error("something went wrong!", err);
}
