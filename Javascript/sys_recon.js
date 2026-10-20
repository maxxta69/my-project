import os from "os";
import {
  Bytes_to_GB,
  Bytes_to_MB,
  Bytes_to_KB,
  //   seconds_to_days,
} from "./conversions.js";

console.log("====== SYSTEM RECONNAISANCE =========\n\n");

try {
  const hostname = os.hostname();
  console.log("Hostname: ", hostname);
} catch (err) {
  console.error("Failed to read hostname: ", err);
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
  //   console.log(
  //     `uid: ${uid}\ngid: ${gid}\nUsername: ${username}\nHome directory: ${homedir}\nShell: ${shell}`,
  //   );

  console.log(`uid: ${uid}`);
  console.log(`gid: ${gid}`);
  console.log(`Username: ${username}`);
  console.log(`Home directory: ${homedir}`);
  console.log(`Shell: ${shell}`);
} catch (err) {
  console.error("Unable to get user information: ", err);
}

try {
  const uptime_sec = os.uptime();
  const days = Math.floor(uptime_sec / 86400);
  const hours = Math.floor((uptime_sec % 86400) / 3600);
  const minutes = Math.floor((uptime_sec % 3600) / 60);
  //   console.log(`Uptime: ${days}day(s), ${hours}hr(s), ${minutes}min(s)`);
  console.log(
    "Uptime: ",
    days,
    "day(s), ",
    hours,
    "hr(s), ",
    minutes,
    "min(s)",
  );
} catch (err) {
  console.error("Failed to read system uptime: ", err);
}

try {
  const { One, Five, Fifteen } = os.loadavg();
  console.log(
    `Load average: 1min = ${One}, 5mins = ${Five}, 15mins = ${Fifteen}`,
  );
} catch (err) {
  console.error("Failed to read load average: ", err);
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
      if (iface.family === "IPv6") break;
      console.log(`\nInterface: ${name}`);
      console.log(`Address: ${iface.address}`);
      console.log(`Netmask: ${iface.netmask}`);
      console.log(`MAC: ${iface.mac}`);
    }
  }
} catch (err) {
  console.error("something went wrong!", err);
}
