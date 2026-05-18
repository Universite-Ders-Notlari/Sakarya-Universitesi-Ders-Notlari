using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Takim
    {
        [Key]
        public int ID { get; set; }
        public byte[] Foto { get; set; }
        public string AdSoyad { get; set; }
        public string Icerik { get; set; }
        public int Tip { get; set; }
    }
}