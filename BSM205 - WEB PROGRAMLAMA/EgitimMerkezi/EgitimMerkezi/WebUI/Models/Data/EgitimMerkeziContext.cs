using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using WebUI.Models;

namespace WebUI.Models.Data
{
    public class EgitimMerkeziContext : DbContext
    {
        public DbSet<Blog> Blog { get; set; }
        public DbSet<Duyuru> Duyuru { get; set; }
        public DbSet<Modul> Modul { get; set; }
        public DbSet<Oneri> Oneri { get; set; }
        public DbSet<Referans> Referans { get; set; }
        public DbSet<Slider> Slider { get; set; }
        public DbSet<Takim> Takim { get; set; }
    }    
}