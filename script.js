function runSyscall(syscall) {
    fetch("syscall.php", {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded"
      },
      body: "syscall=" + syscall
    })
    .then(response => response.text())
    .then(data => {
      document.getElementById("output").innerHTML = data;
    });
  }
  